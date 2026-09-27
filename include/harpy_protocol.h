/* HARPY protocol HP 0x5048 — port from harpy-ios Network/HarpyProtocol.swift
 * Little-endian. TLS 1.2 recommended on the wire (port 7777).
 */
#ifndef HARPY_PROTOCOL_H
#define HARPY_PROTOCOL_H

#include <stdint.h>

#define HP_MAGIC          0x5048u
#define HP_VERSION        2
#define HP_DEFAULT_PORT   7777
#define HP_MAX_NAME       32
#define HP_MAX_PASS       64
#define HP_MAX_TEXT       240
#define HP_MAX_PAYLOAD    8192
#define HP_HEADER_SIZE    8
#define HP_TOKEN_LEN      48

#define PKT_LOGIN         1
#define PKT_LIST          2
#define PKT_SEND          3
#define PKT_HISTORY       4
#define PKT_RESUME        5
#define PKT_GROUP_CREATE  6
#define PKT_FILE_BEGIN    7
#define PKT_FILE_CHUNK    8
#define PKT_EDIT          9
#define PKT_OK            10
#define PKT_ERR           11
#define PKT_USER          12
#define PKT_MSG           13
#define PKT_PRESENCE      14
#define PKT_DELETE        16
#define PKT_LOGOUT        17
#define PKT_GROUP_INVITE  18
#define PKT_FILE_END      19
#define PKT_USER_CREATE   20

#define OK_LOGIN          1
#define OK_LIST           2
#define OK_SEND           3
#define OK_HISTORY        4
#define OK_RESUME         5
#define OK_GROUP          6
#define OK_FILE           7
#define OK_EDIT           8
#define OK_DELETE         9
#define OK_LOGOUT         10
#define OK_INVITE         11
#define OK_FILE_END       12
#define OK_USER_CREATE    13

#define MSG_FLAG_DELETED  1u
#define MSG_FLAG_EDITED   2u
#define MSG_FLAG_FILE     4u
#define MSG_FLAG_GROUP    8u

#pragma pack(push, 1)
typedef struct {
    uint16_t magic;
    uint16_t type;
    uint32_t length;
} hp_hdr_t;

typedef struct {
    uint32_t id;
    uint32_t flags;
    uint64_t ts;
    char from[32];
    char to[32];
    char text[240];
} hp_msg_t;
#pragma pack(pop)

#endif

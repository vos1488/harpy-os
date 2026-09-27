# Xiaomi Mi 5c (meri) — как поставить HARPY OS

## Железо

| | |
|---|---|
| Код | meri |
| SoC | Pinecone Surge S1 (4×A53 2.2 + 4×A53 1.4), Mali-T860 MP4, 28 нм |
| Экран | 5.15" IPS 1080×1920 |
| ОЗУ / ROM | 3 ГБ / 64 ГБ |
| Android | 7.1 Nougat, API 24/25, MIUI 8…11 (последняя V11.0.3.0.NCJCNXM) |
| hardware | `androidboot.hardware=song` |
| boot.img | pagesize 4096, kernel_off 0x0a080000, ramdisk_off 0x0c400000, hash sha256 |

Ядро Surge S1 **не пишем**. Mainline для S1 мёртв. HARPY на meri = свой userspace поверх того, что уже грузится.

## Путь установки v0.1

1. Разблокировать загрузчик официальным Mi Unlock.
2. Прошить MIUI 7.1 / Xiaomi.eu V10.2.1.0.NCJCNXM (TWRP или MiFlash, **clean all**, не lock).
3. Включить USB debugging.
4. `adb install harpy-os.apk` — лаунчер с intent `HOME` + `LAUNCHER`.
5. Приложение по умолчанию → рабочий стол → HARPY.
6. Опционально root (исторически SuperSU / meri_tools usedbytes).

TWRP для meri существовал в 2017 (сборка swinder0161). Зеркала часто мёртвы.

```
fastboot boot twrp-meri.img
adb sideload harpy-os.zip
```

## Что НЕ делать в v0.1

- Не собирать своё ядро S1.
- Не ждать LineageOS/AOSP для meri.
- Не путать с Meizu M5c (это другой телефон, MT6737).

## Отладка без телефона

```
cd sim
python3 harpy_sim.py
```

Симулятор рисует 1080×1920 1-bit стол с кириллицей.

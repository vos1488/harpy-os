# HARPY .harpyapp — формат пакетов

Пакет = zip-архив с расширением `.harpyapp`.

```
id.harpyapp
  manifest.json
  icon.1bpp          # 16x16, row-major, 32 байта
  app.dex            # Android 7.1 / API 24-25
  # или
  app.py             # симулятор / Linux framebuffer
```

## manifest.json

```json
{
  "id": "su.vos9.harpy.files",
  "name": "Files",
  "name_ru": "Файлы",
  "version": "0.1.0",
  "icon": "icon.1bpp",
  "entry": "app.dex",
  "abi": "harpy-app-1",
  "min_api": 24,
  "permissions": ["storage"]
}
```

Категорически нет apt / Play / MineOS App Market.
Установка: положить файл в `/sdcard/Harpy/Apps/` или `adb install` системного APK-лаунчера.

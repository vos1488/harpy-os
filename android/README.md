# HARPY на телефоне (Mi 5c / meri)

Это HOME-лаунчер под палец. Не ядро. Android 7.1 API 24/25, 1080×1920.

## Сборка

Нужен Android SDK 25 (Android Studio или command-line tools).

```
cd android
./gradlew assembleDebug
adb install -r app/build/outputs/apk/debug/app-debug.apk
adb shell cmd package set-home-activity os.harpy/.HarpyActivity
```

На телефоне: Настройки → Приложения по умолчанию → Рабочий стол → HARPY.

## Палец

- плитки 96×96 логических = 288×288 px
- док: СТОЛ | НАЗАД | КЛАВ
- свайп вправо = назад
- свайп вниз по шапке = закрыть
- ЙЦУКЕН на экране, клавиши ~84 px
- системная «Назад» не выходит из HARPY

# RGBW LED Driver

## Описание

`rgbw_driver` - драйвер на языке C99 для управления RGBW LED-контроллером по интерфейсу I2C.

Драйвер использует предоставленный I2C API:

- `I2C_Init`
- `I2C_Start`
- `I2C_Write`
- `I2C_Stop`

Прямой доступ к аппаратным регистрам микроконтроллера не используется.

---

## Возможности

Драйвер поддерживает:

- инициализацию RGBW-контроллера;
- установку яркости каналов `D1–D4`;
- включение и выключение одного канала;
- включение и выключение всех каналов;
- установку RGB-цвета через каналы:
  - `D1` - Red;
  - `D2` - Green;
  - `D3` - Blue;
- проверку ошибок после каждой I2C-операции.

---

## Сборка

```bash
cmake -S . -B build
cmake --build build
```

Проект собирается как C99-код с флагами:

```bash
-Wall -Wextra -std=c99
```

---

## Запуск примера

Linux/macOS:

```bash
./build/rgbw_example
echo $?
```

Ожидаемый код возврата:

```text
0
```

---

## Пример использования

```c
#include "rgbw_driver.h"

#define RGBW_I2C_ADDRESS (0x3CU)

int main(void)
{
    RGBW_Handle_t rgbw;
    I2C_Error_t status;

    status = RGBW_Init(&rgbw,
                       I2C_CH0,
                       I2C_FREQ_100_KHZ,
                       RGBW_I2C_ADDRESS);

    if (status != I2C_ERR_SUCCESS)
    {
        return 1;
    }

    status = RGBW_SetAllChannelsState(&rgbw, 1U);

    if (status != I2C_ERR_SUCCESS)
    {
        return 1;
    }

    status = RGBW_SetRGB(&rgbw, 255U, 0U, 0U);

    if (status != I2C_ERR_SUCCESS)
    {
        return 1;
    }

    return 0;
}
```

---

## Публичный API

```c
I2C_Error_t RGBW_Init(RGBW_Handle_t *handle,
                      I2C_Ch_t i2c_ch,
                      I2C_Freq_t i2c_freq,
                      uint8_t i2c_addr);

I2C_Error_t RGBW_SetBrightness(RGBW_Handle_t *handle,
                               RGBW_Channel_t channel,
                               uint8_t brightness);

I2C_Error_t RGBW_SetChannelState(RGBW_Handle_t *handle,
                                 RGBW_Channel_t channel,
                                 uint8_t enabled);

I2C_Error_t RGBW_SetAllChannelsState(RGBW_Handle_t *handle,
                                     uint8_t enabled);

I2C_Error_t RGBW_SetRGB(RGBW_Handle_t *handle,
                        uint8_t red,
                        uint8_t green,
                        uint8_t blue);
```

---

## Используемые регистры

| Адрес | Назначение |
|---|---|
| `0x00` | Shutdown Register |
| `0x05` | PWM Register D1 |
| `0x06` | PWM Register D2 |
| `0x07` | PWM Register D3 |
| `0x08` | PWM Register D4 |
| `0x25` | PWM Update Register |
| `0x2A` | LED Control Register D1 |
| `0x2B` | LED Control Register D2 |
| `0x2C` | LED Control Register D3 |
| `0x2D` | LED Control Register D4 |
| `0x4A` | Global Control Register |
| `0x4F` | Reset Register |

После записи в PWM-регистры или LED Control-регистры драйвер записывает `0x00` в `0x25`, чтобы применить изменения.

---

## I2C-адрес

I2C API принимает 7-битный адрес устройства.

Если в документации указан полный адресный байт записи, например:

```text
0x78
```

то в драйвер надо передавать:

```c
0x78U >> 1U
```

То есть:

```c
#define RGBW_I2C_ADDRESS (0x3CU)
```

---

## Обработка ошибок

Все функции возвращают `I2C_Error_t`.

Если любая I2C-операция завершается ошибкой, текущая операция прекращается, а ошибка возвращается вызывающему коду.

Пример:

```c
status = RGBW_SetRGB(&rgbw, 0U, 255U, 0U);

if (status != I2C_ERR_SUCCESS)
{
    return 1;
}
```

---

## I2C mock

Файл `examples/i2c_mock.c` нужен только для локальной сборки и проверки примера на ПК.

На реальном микроконтроллере вместо него должна использоваться настоящая реализация предоставленного I2C API.

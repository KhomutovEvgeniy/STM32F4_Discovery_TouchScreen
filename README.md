# STM32F4_Discovery_TouchScreen
Поднята работа с сенсорным экраном с STM32F4DISCOVERY
В проекте реализована рисовалка на базе сенсорного экрана.
Процедура калибровки сенсорного экрана запускается, если в момент подачи питания на МК была нажата пользовательская кнопка на шилде МК. По окончании калибровки экран обновится (будет белый), калибровочные коэффициенты сохранятся во флеш, можно попробовать нарисовать какую-нибудь рожицу :).
Если калибровка не требуется при запуске МК - просто подать питание - калибровочные коэффициенты считаются из флеша МК (с предыдущей калибровки).

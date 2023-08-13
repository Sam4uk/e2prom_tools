# e2prom_tools

Додаткові утиліти для роботи з EEPROM

## e2clean

Генератор файлу для очищення EEPROM

## files

version_info
version_discovery

### dependence
sudo apt-get install libboost-all-dev make cmake libcurl4-gnutls-dev liblog4cpp5v5
sudo apt-get install liblog4cxx-dev


```zsh
mkdir build
cmake -B build
cmake --build build
```


### Secrets


|        GIT SECRET        |      example       | Опис                              | |
|--------------------------|:------------------:|-----------------------------------|-|
|NANIT_SCHEME              |https               |Схема доступу до вузла             |1|
|NANIT_HOST                |docs.ieu.edu.ua     |Ім'я чи адреса вузла               |2|
|NANIT_PATH_GET_SERIAL     |seriynyk.php   |Шлях до скрипта який видає серійний номер|3|
|NANIT_QUERY_GET_SERIAL    |SN=1                |Запит на видачу серійного номеру   |4|
|NANIT_PATH_CONFIRM_SERIAL|seriynyk.php|Шлях до скрипта який отримує підвердження реєстрації номеру|5|
|NANIT_QUERY_CONFIRM_SERIAL|SN=1                |Запит-звіт про успішений запис номеру|6|
|NANIT_PATH_FAIL_SERIAL    |seriynyk.php        |Шлях до скрипта який скасування реєстрації|7|
|NANIT_QUERY_FAIL_SERIAL   |SN=1                |Запит про хибний запис             |8|

```
https://docs.ieu.edu.ua/seriynyk.php?get=0
https://docs.ieu.edu.ua/seriynyk.php?number=0232122&status=fail
https://docs.ieu.edu.ua/seriynyk.php?number=0232122&status=ok
```
[![Build Status](https://travis-ci.org/AdmiralBULLLdoG/Coursework-a-game-of-100-matches.svg?branch=master)](https://travis-ci.org/AdmiralBULLLdoG/Coursework-a-game-of-100-matches)
# Курсовой проект игра <100 спичек>
Игра "100 спичек". Из кучки, первоначально содержащей 100 спичек, двое играющих поочередно берут по несколько спичек: не менее одной и не более десяти. Выигрывает взявший последнюю спичку.


## Тесты
При написании тестов я пользовался библиотекой CMock.
Всю документацию по ней вы можете найти по этой ссылке: https://github.com/ThrowTheSwitch/CMock.

### Запуск тестов на вашем ПК
Чтобы запустить мои тесты вам потребуется установка Ruby.
Проверить установлен ли он можно следующей командой:
```
ruby --version
```
Установить командой:
```
sudo apt-get install ruby-full
```
Так же вам потребуется склонировать репозиторий в корневую папку моего репозитория следующей командой:
```
git clone --recursive https://github.com/throwtheswitch/cmock.git
```
И выполнить следующие команды:
```
cd cmock
bundle install
```
На этом все. Вы готовы к запуску моей программы.

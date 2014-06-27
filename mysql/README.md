![MySQL](http://www.calitosway.net/wp-content/uploads/2014/03/mysql-logo.jpg)
![MariaDB](http://badges.mariadb.org/logo/Mariadb-seal-shaded-browntext.png)

## Change password for user

```
mysql -u root -h localhost
use mysql;
update user set password = password('PASSWORD') where user = 'USERID';
flush privileges;
```
> 참조: http://blog.naver.com/illi0001/140120290640

## Change password for root

```
# mysqld shutdown (kill or shutdown)
# mysqld --skip-grant
update user set password = password('PASSWORD') where user = 'root';
flush privileges;
```
> 참조: http://blog.naver.com/illi0001/140120291001

## Change charset utf8 for database

#### 1. mysql client에서 변경하는 방법
```
mysql -u root -h localhost mysql
status
set character_set_database=utf8
set character_set_server=utf8
quit

# mysqld restart
```
> 참조: http://blog.naver.com/illi0001/140121564550 <br>

#### 2. my.cnf 수정하는 방법

```
[client]
default-character-set=utf8

[mysqld]
character-set-client-handshake=FALSE
init_connect="SET collation_connection = utf8_general_ci"
init_connect="SET NAMES utf8"
character-set-server = utf8
collation-server = utf8_general_ci

[mysql]
default-character-set=utf8

# mysqld restart
```
> 참조: http://blog.naver.com/illi0001/140121564550 <br>

#### 3. Table의 charset 변경
```
alter table TABLE_NAME convert to charset utf8;
```
> 참조: [mysql-한글설정-character-set-utf-8-설정](http://brain.payzip.co.kr/2013/07/23/mysql-%ED%95%9C%EA%B8%80%EC%84%A4%EC%A0%95-character-set-utf-8-%EC%84%A4%EC%A0%95//)

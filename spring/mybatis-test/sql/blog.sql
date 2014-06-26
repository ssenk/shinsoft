create table blog (
  id int auto_increment not null primary key
, subject varchar(1024)
, body varchar(2000)
, datetime date
);
-- --------------------------------------------------------
-- Хост:                         127.0.0.1
-- Версия сервера:               8.0.25 - MySQL Community Server - GPL
-- Операционная система:         Win64
-- HeidiSQL Версия:              11.2.0.6213
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Дамп структуры базы данных matvey
DROP DATABASE IF EXISTS `matvey`;
CREATE DATABASE IF NOT EXISTS `matvey` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `matvey`;


-- Дамп структуры для таблица matvey.client
DROP TABLE IF EXISTS `client`;
CREATE TABLE IF NOT EXISTS `client` (
  `idklient` int NOT NULL AUTO_INCREMENT,
  `fio` varchar(250) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `adr` varchar(500) DEFAULT NULL,
  `idschet` int DEFAULT NULL,
  PRIMARY KEY (`idklient`),
  UNIQUE KEY `idclient` (`idklient`),
  UNIQUE KEY `i3` (`fio`),
  KEY `FKschet` (`idschet`),
  CONSTRAINT `FKschet` FOREIGN KEY (`idschet`) REFERENCES `schet` (`idschet`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы matvey.client: ~10 rows (приблизительно)
DELETE FROM `client`;
/*!40000 ALTER TABLE `client` DISABLE KEYS */;
INSERT INTO `client` (`idklient`, `fio`, `adr`, `idschet`) VALUES
	(1, 'Ситник М.И.', 'г. Бобруйск, ул. Крылова, 152', 14),
	(2, 'Микаилов В.В.', 'г. Минск, ул. Радиальная, 11', 11),
	(3, 'Туля Е.О.', 'г. Жодино, ул. Неманская, 15-6', 13),
	(4, 'Бочаров М.Н.', 'г. Бобруйск, ул. Минская, 14-2', 19),
	(5, 'Плохотский И.М.', 'г. Рогачев, ул. Юбилейная, 23', 12),
	(6, 'Бобр Ю.Н.', 'г. Мозырь, ул.Б.Юности, 68', 15),
	(7, 'Кузьменко Е.В.', 'г.Гомель, ул.Б.Хмельницкого 72 ', 17),
	(8, 'Стаховский В.В.', 'г.Калинковичи, ул.Гастело, 33', 16),
	(9, 'Фещенко В.П.', 'г.Речица, ул.8 марта, 12', 20),
	(10, 'Комисаров Т.В.', 'г.Житковичи, ул.Пушкина,69', 18);
/*!40000 ALTER TABLE `client` ENABLE KEYS */;



-- Дамп структуры для таблица matvey.firma
DROP TABLE IF EXISTS `firma`;
CREATE TABLE IF NOT EXISTS `firma` (
  `nazvan` varchar(500) NOT NULL DEFAULT '',
  `uradr` varchar(500) NOT NULL DEFAULT '',
  `phone` varchar(50) NOT NULL DEFAULT '',
  `idschet` int NOT NULL,
  KEY `FKschetf` (`idschet`),
  KEY `I1` (`nazvan`),
  CONSTRAINT `FKschetf` FOREIGN KEY (`idschet`) REFERENCES `schet` (`idschet`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Описание фирмы';

-- Дамп данных таблицы matvey.firma: ~0 rows (приблизительно)
DELETE FROM `firma`;
/*!40000 ALTER TABLE `firma` DISABLE KEYS */;
INSERT INTO `firma` (`nazvan`, `uradr`, `phone`, `idschet`) VALUES
	('Инспектор гаджет', 'г.Мозырь ул.Чапаева 28', '+375336512162', 4);
/*!40000 ALTER TABLE `firma` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.kadr
DROP TABLE IF EXISTS `kadr`;
CREATE TABLE IF NOT EXISTS `kadr` (
  `idkadry` int NOT NULL AUTO_INCREMENT,
  `fio` varchar(250) NOT NULL,
  `dolg` varchar(500) DEFAULT NULL,
  `obraz` enum('Высшее','Среднеспециальное','Среднее','Базовое') NOT NULL,
  `oklad` float(12,0) NOT NULL,
  `data` date NOT NULL,
  PRIMARY KEY (`idkadry`),
  UNIQUE KEY `idkadr` (`idkadry`),
  UNIQUE KEY `i2` (`fio`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Сотрудники фирмы';

-- Дамп данных таблицы matvey.kadr: ~7 rows (приблизительно)
DELETE FROM `kadr`;
/*!40000 ALTER TABLE `kadr` DISABLE KEYS */;
INSERT INTO `kadr` (`idkadry`, `fio`, `dolg`, `obraz`, `oklad`, `data`) VALUES
	(1, 'Нонейм В.В.', 'Директор', 'Высшее', 1000, '2018-01-28'),
	(2, 'Сопот Т.Э.', 'Бухгалтер', 'Высшее', 750, '2018-02-20'),
	(3, 'Невмержицкий Н.Е.', 'Водитель', 'Среднеспециальное', 550, '2020-02-20'),
	(4, 'Телеш Т.Н.', 'Менеджер ', 'Среднеспециальное', 600, '2021-04-15'),
	(5, 'Гуненко Н.Н.', 'Продавец', 'Среднеспециальное', 550, '2018-02-21'),
	(6, 'Ивашин А.С.', 'техник-Программист', 'Среднеспециальное', 600, '2021-04-12'),
	(7, 'Лубовский А.В.', 'продавец', 'Среднеспециальное', 550, '2021-05-26');
/*!40000 ALTER TABLE `kadr` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.naklad
DROP TABLE IF EXISTS `naklad`;
CREATE TABLE IF NOT EXISTS `naklad` (
  `idnakladnaya` int NOT NULL AUTO_INCREMENT,
  `idtovar` int NOT NULL,
  `kolvo` int unsigned NOT NULL,
  `summa` float(12,0) unsigned NOT NULL,
  `idklient` int NOT NULL,
  PRIMARY KEY (`idnakladnaya`),
  UNIQUE KEY `idnaklad` (`idnakladnaya`),
  KEY `FKtovarn` (`idtovar`),
  KEY `FK_nakladnaya_klient` (`idklient`),
  CONSTRAINT `FK_nakladnaya_klient` FOREIGN KEY (`idklient`) REFERENCES `client` (`idklient`),
  CONSTRAINT `FKtovarn` FOREIGN KEY (`idtovar`) REFERENCES `tovar` (`idtovar`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Накладные на товар';

-- Дамп данных таблицы matvey.naklad: ~5 rows (приблизительно)
DELETE FROM `naklad`;
/*!40000 ALTER TABLE `naklad` DISABLE KEYS */;
INSERT INTO `naklad` (`idnakladnaya`, `idtovar`, `kolvo`, `summa`, `idklient`) VALUES
	(1, 1, 3, 60, 1),
	(2, 2, 5, 100, 2),
	(3, 6, 1, 55, 6),
	(4, 7, 1, 20, 4),
	(5, 10, 5, 55, 7);
/*!40000 ALTER TABLE `naklad` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.postav
DROP TABLE IF EXISTS `postav`;
CREATE TABLE IF NOT EXISTS `postav` (
  `idpostav` int NOT NULL AUTO_INCREMENT,
  `fio` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `adr` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `idschet` int DEFAULT NULL,
  PRIMARY KEY (`idpostav`),
  UNIQUE KEY `idpostav` (`idpostav`),
  UNIQUE KEY `i4` (`fio`),
  KEY `FKschetp` (`idschet`),
  CONSTRAINT `FKschetp` FOREIGN KEY (`idschet`) REFERENCES `schet` (`idschet`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Поставщики';

-- Дамп данных таблицы matvey.postav: ~10 rows (приблизительно)
DELETE FROM `postav`;
/*!40000 ALTER TABLE `postav` DISABLE KEYS */;
INSERT INTO `postav` (`idpostav`, `fio`, `adr`, `idschet`) VALUES
	(1, 'ЧТУП ТимБас', 'г.Гродно, ул.Суворова,254', 4),
	(2, 'ЧТУП РОТАКОН', 'г.Полоцк, ул.Советская 22', 3),
	(3, 'ЧТУП Бурштат', 'г.Витебск, ул.Ф.Скорины, 59', 5),
	(4, 'ЧТУП ТехЦентр', 'г.Солигорск, ул.Я.Коласа,76', 1),
	(5, 'ЧТУП Бимтэк', 'г.Брест,ул.Ленина,43', 2),
	(6, 'ОДО Белтехстрой', 'г.Пинск,ул.Советских Пограничников,92', 7),
	(7, 'ООО Горизонт', 'г.Лида,ул.Фолюш,67', 8),
	(8, 'ООО Алтерм', 'г.Новополоцк,ул.Е.Полоцкой,41', 10),
	(9, 'ОДО Белросимпорт', 'г.Мозырь,ул.Мостовая,3', 6),
	(10, 'ЧТУП Комплайт', 'г.Кобрин,ул.Фрунзе,10', 9);
/*!40000 ALTER TABLE `postav` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.schet
DROP TABLE IF EXISTS `schet`;
CREATE TABLE IF NOT EXISTS `schet` (
  `idschet` int NOT NULL AUTO_INCREMENT,
  `bank` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `numchet` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `status` int NOT NULL DEFAULT '0',
  `data` date NOT NULL,
  `creditstat` enum('Y','N') NOT NULL,
  `summa` float(12,0) DEFAULT NULL,
  PRIMARY KEY (`idschet`),
  UNIQUE KEY `idschet` (`idschet`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы matvey.schet: ~20 rows (приблизительно)
DELETE FROM `schet`;
/*!40000 ALTER TABLE `schet` DISABLE KEYS */;
INSERT INTO `schet` (`idschet`, `bank`, `numchet`, `status`, `data`, `creditstat`, `summa`) VALUES
	(1, 'Паритетбанк', '681735413', 1250, '2020-03-19', '', 3300),
	(2, 'Альфа-Банк', '901235723', 0, '2019-10-23', '', 5200),
	(3, 'ВТББанк', '561384613', 0, '2020-08-12', '', 18000),
	(4, 'Белинвестбанк', '719837645', 200, '2018-02-24', '', 4000),
	(5, 'Белгазпромбанк', '564718379', 0, '2016-09-28', '', 8700),
	(6, 'Приорбанк', '681739138', 820, '2017-05-11', '', 2200),
	(7, 'МоскваМинск', '000025215', 0, '2019-09-24', '', 1000),
	(8, 'Беларусбанк', '985578067', 765, '2016-06-06', '', 4000),
	(9, 'Беларусбанк', '641923519', 35, '2018-07-20', '', 2314),
	(10, 'Белинвестбанк', '412455125', 78, '2019-08-15', '', 100),
	(11, 'ВТББанк', '214758941', 532, '2018-02-17', '', 1000),
	(12, 'БПС-Сбербанк', '124789812', 79, '2019-09-26', '', 700),
	(13, 'Приорбанк', '709123487', 7, '2018-08-30', '', 93),
	(14, 'Белагропромбанк', '908746123', 90, '2015-07-01', '', 100),
	(15, 'Альфа-Банк', '679854334', 78, '2016-02-27', '', 432),
	(16, 'Банк БелВЭБ', '563354363', 77, '2018-08-29', '', 90),
	(17, 'Дабрабыт банк', '439875354', 300, '2019-08-19', '', 451),
	(18, 'Банк Решение', '809645352', 456, '2015-07-20', '', 706),
	(19, 'БНБ-банк', '894213567', 0, '2017-01-28', '', 9000),
	(20, 'БТА банк', '765433653', 0, '2018-08-20', '', 1000);
/*!40000 ALTER TABLE `schet` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.sklad
DROP TABLE IF EXISTS `sklad`;
CREATE TABLE IF NOT EXISTS `sklad` (
  `Nsklad` int unsigned NOT NULL AUTO_INCREMENT,
  `adress` varchar(5000) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`Nsklad`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы matvey.sklad: ~10 rows (приблизительно)
DELETE FROM `sklad`;
/*!40000 ALTER TABLE `sklad` DISABLE KEYS */;
INSERT INTO `sklad` (`Nsklad`, `adress`) VALUES
	(1, 'г.Орша,ул. Пушкина,13'),
	(2, 'г. Минск, ул. Первомайская,44'),
	(3, 'г.Гомель, ул. Б.Хмельницкого,13'),
	(4, 'г. Бобруйск, ул. Холмогорская,74'),
	(5, 'г. Могилев, ул.Б.Непокоренных, 19'),
	(6, 'г.Мозырь, ул.Фрунзе, 2'),
	(7, 'г.Новоплоцк, ул.Социалистическая 7'),
	(8, 'г.Витебск, ул.50 лет СССР'),
	(9, 'г.Солигорск, ул.Рябиновая 7'),
	(10, 'г.Гродно, ул.Комунальная 16');
/*!40000 ALTER TABLE `sklad` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.tovar
DROP TABLE IF EXISTS `tovar`;
CREATE TABLE IF NOT EXISTS `tovar` (
  `idtovar` int NOT NULL AUTO_INCREMENT,
  `naimen` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `ed_izm` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `cena` int NOT NULL,
  `idpostav` int NOT NULL,
  `sklad` int unsigned NOT NULL,
  `sort` int NOT NULL,
  PRIMARY KEY (`idtovar`),
  UNIQUE KEY `idtovar` (`idtovar`),
  KEY `FKpostavt` (`idpostav`),
  KEY `FK_tovar_sklad` (`sklad`),
  KEY `i5` (`naimen`) USING BTREE,
  CONSTRAINT `FK_tovar_sklad` FOREIGN KEY (`sklad`) REFERENCES `sklad` (`Nsklad`),
  CONSTRAINT `FKpostavt` FOREIGN KEY (`idpostav`) REFERENCES `postav` (`idpostav`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Список товаров нормализованный';

-- Дамп данных таблицы matvey.tovar: ~10 rows (приблизительно)
DELETE FROM `tovar`;
/*!40000 ALTER TABLE `tovar` DISABLE KEYS */;
INSERT INTO `tovar` (`idtovar`, `naimen`, `ed_izm`, `cena`, `idpostav`, `sklad`, `sort`) VALUES
	(1, 'Ноутбук', 'шт', 1499, 1, 1, 0),
	(2, 'Игровая приставка', 'шт', 2455, 2, 1, 0),
	(3, 'Мышка', 'шт', 15, 1, 2, 2),
	(4, 'Фен', 'шт', 59, 2, 2, 1),
	(5, 'Телвизор', 'шт', 4500, 1, 2, 3),
	(6, 'Обогреватель', 'шт', 100, 4, 1, 2),
	(7, 'Чайник', 'шт', 40, 6, 4, 3),
	(8, 'Монитор', 'шт', 700, 7, 3, 2),
	(9, 'Телефон', 'шт', 500, 4, 2, 1),
	(10, 'Миксер', 'шт', 55, 6, 3, 2);
/*!40000 ALTER TABLE `tovar` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.transport
DROP TABLE IF EXISTS `transport`;
CREATE TABLE IF NOT EXISTS `transport` (
  `idtransport` int NOT NULL AUTO_INCREMENT,
  `nomer` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `marka` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `gruz` float(12,0) NOT NULL,
  `god` int NOT NULL,
  `fio` varchar(450) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `data` date DEFAULT NULL,
  `nsklad` int unsigned DEFAULT NULL,
  PRIMARY KEY (`idtransport`) USING BTREE,
  UNIQUE KEY `i5` (`nomer`),
  KEY `FK_transport_sklad` (`nsklad`),
  CONSTRAINT `FK_transport_sklad` FOREIGN KEY (`nsklad`) REFERENCES `sklad` (`Nsklad`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы matvey.transport: ~0 rows (приблизительно)
DELETE FROM `transport`;
/*!40000 ALTER TABLE `transport` DISABLE KEYS */;
INSERT INTO `transport` (`idtransport`, `nomer`, `marka`, `gruz`, `god`, `fio`, `data`, `nsklad`) VALUES
	(2, 'AI 4212-6', 'MAN', 1000, 2011, 'АвтоСерж-транс', '2020-11-26', 4),
	(3, 'AM 1672-6', 'DAF', 15000, 2018, 'АвтоСерж-транс', '2020-12-11', 8),
	(4, 'AK 4956-6', 'DAF', 600, 2019, 'Невмержицкий Н.Е.', '2021-01-29', 1),
	(5, 'AI 6326-6', 'Volvo', 100, 2010, 'АвтоСерж-транс', '2021-03-25', 5),
	(6, 'AY 6212-3', 'Iveco', 15000, 2012, 'АвтоСерж-транс', '2021-02-17', 6),
	(7, 'AR 8967-7', 'Mercedes-benz', 8000, 2017, 'АвтоСерж-транс', '2021-04-20', 2);
/*!40000 ALTER TABLE `transport` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.zakaz
DROP TABLE IF EXISTS `zakaz`;
CREATE TABLE IF NOT EXISTS `zakaz` (
  `idzakaz` int NOT NULL AUTO_INCREMENT,
  `data` date DEFAULT NULL,
  `idclient` int NOT NULL,
  `idtovar` int NOT NULL,
  `kolvo` int NOT NULL DEFAULT '0',
  `opl` enum('Y','N') DEFAULT NULL,
  PRIMARY KEY (`idzakaz`) USING BTREE,
  UNIQUE KEY `id_zakaz` (`idzakaz`) USING BTREE,
  KEY `FKtovar` (`idtovar`) USING BTREE,
  KEY `FKclientz` (`idclient`) USING BTREE,
  CONSTRAINT `FKclientz` FOREIGN KEY (`idclient`) REFERENCES `client` (`idklient`),
  CONSTRAINT `FKtovar` FOREIGN KEY (`idtovar`) REFERENCES `tovar` (`idtovar`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Список заказов п 10';

-- Дамп данных таблицы matvey.zakaz: ~0 rows (приблизительно)
DELETE FROM `zakaz`;
/*!40000 ALTER TABLE `zakaz` DISABLE KEYS */;
INSERT INTO `zakaz` (`idzakaz`, `data`, `idclient`, `idtovar`, `kolvo`, `opl`) VALUES
	(1, '2021-05-19', 2, 2, 3, NULL),
	(2, '2021-05-19', 4, 3, 1, NULL),
	(3, '2021-05-22', 5, 3, 1, NULL),
	(4, '2019-03-16', 6, 6, 1, NULL);
/*!40000 ALTER TABLE `zakaz` ENABLE KEYS */;

-- Дамп структуры для представление matvey.a
DROP VIEW IF EXISTS `a`;
-- Удаление временной таблицы и создание окончательной структуры представления
DROP TABLE IF EXISTS `a`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `a` AS select `kadr`.`fio` AS `fio`,`kadr`.`data` AS `data` from `kadr` where (`kadr`.`data` < '2021-01-01');

-- Дамп структуры для представление matvey.b
DROP VIEW IF EXISTS `b`;
-- Удаление временной таблицы и создание окончательной структуры представления
DROP TABLE IF EXISTS `b`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `b` (`marka`,`gruz`,`god`,`DATA`) AS select `transport`.`marka` AS `marka`,`transport`.`gruz` AS `gruz`,`transport`.`god` AS `god`,`transport`.`data` AS `DATA` from `transport` where ((`transport`.`data` < '2021-01-01') and (`transport`.`gruz` = 1000));

-- Дамп структуры для представление matvey.c
DROP VIEW IF EXISTS `c`;
-- Удаление временной таблицы и создание окончательной структуры представления
DROP TABLE IF EXISTS `c`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `c` AS select `p`.`fio` AS `fio`,`p`.`adr` AS `uradr` from (`tovar` `t` join `postav` `p`) where ((`p`.`idpostav` = `t`.`idpostav`) and (`t`.`sort` = 1) and (`t`.`cena` = 500) and (`t`.`naimen` = 'Телефон'));

-- Дамп структуры для представление matvey.d
DROP VIEW IF EXISTS `d`;
-- Удаление временной таблицы и создание окончательной структуры представления
DROP TABLE IF EXISTS `d`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `d` (`fio`,`bank`,`numchet`) AS select `p`.`fio` AS `fio`,`s`.`bank` AS `bank`,`s`.`numchet` AS `numchet` from (`schet` `s` join `postav` `p`) where ((`p`.`fio` = 'ЧТУП ТимБас') and (`p`.`idschet` = `s`.`idschet`));

-- Дамп структуры для представление matvey.e
DROP VIEW IF EXISTS `e`;
-- Удаление временной таблицы и создание окончательной структуры представления
DROP TABLE IF EXISTS `e`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `e` AS select `kadr`.`fio` AS `fio`,`kadr`.`dolg` AS `dolg` from (`kadr` join `transport` on((`kadr`.`fio` = `transport`.`fio`)));

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;

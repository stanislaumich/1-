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


-- Дамп структуры базы данных dmaslak
DROP DATABASE IF EXISTS `dmaslak`;
CREATE DATABASE IF NOT EXISTS `dmaslak` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `dmaslak`;

-- Дамп структуры для таблица dmaslak.firma
DROP TABLE IF EXISTS `firma`;
CREATE TABLE IF NOT EXISTS `firma` (
  `firma` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT '',
  `uradr` varchar(500) NOT NULL DEFAULT '',
  `telefon` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT '',
  `Nschet` int NOT NULL,
  KEY `I1` (`firma`) USING BTREE,
  KEY `FKschetf` (`Nschet`) USING BTREE,
  CONSTRAINT `FKschetf` FOREIGN KEY (`Nschet`) REFERENCES `schet` (`n`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Описание фирмы';

-- Дамп данных таблицы dmaslak.firma: ~0 rows (приблизительно)
DELETE FROM `firma`;
/*!40000 ALTER TABLE `firma` DISABLE KEYS */;
INSERT INTO `firma` (`firma`, `uradr`, `telefon`, `Nschet`) VALUES
	('Инспектор гаджет', 'г.Мозырь ул.Чапаева 28', '+375336512162', 4);
/*!40000 ALTER TABLE `firma` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.kadry
DROP TABLE IF EXISTS `kadry`;
CREATE TABLE IF NOT EXISTS `kadry` (
  `N` int NOT NULL AUTO_INCREMENT,
  `fio` varchar(250) NOT NULL,
  `dolg` varchar(500) DEFAULT NULL,
  `obraz` enum('Высшее','Среднеспециальное','Среднее','Базовое') NOT NULL,
  `salary` float(12,0) unsigned NOT NULL,
  `data` date NOT NULL,
  PRIMARY KEY (`N`) USING BTREE,
  UNIQUE KEY `i2` (`fio`),
  UNIQUE KEY `idkadr` (`N`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Сотрудники фирмы';

-- Дамп данных таблицы dmaslak.kadry: ~6 rows (приблизительно)
DELETE FROM `kadry`;
/*!40000 ALTER TABLE `kadry` DISABLE KEYS */;
INSERT INTO `kadry` (`N`, `fio`, `dolg`, `obraz`, `salary`, `data`) VALUES
	(2, 'Аверкова И.В.', 'Бухгалтер', 'Высшее', 750, '2018-02-20'),
	(3, 'Долбик К.В.', 'Водитель', 'Среднеспециальное', 550, '2020-02-20'),
	(4, 'Савицкий А.Н.', 'Менеджер ', 'Среднеспециальное', 600, '2020-02-20'),
	(5, 'Зарянина Т.Н.', 'Продавец', 'Среднеспециальное', 550, '2020-02-20'),
	(6, 'Ивашин А.С.', 'техник-Программист', 'Среднеспециальное', 600, '2019-04-12'),
	(7, 'Лубовский А.В.', 'продавец', 'Среднеспециальное', 550, '2019-05-26');
/*!40000 ALTER TABLE `kadry` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.klient
DROP TABLE IF EXISTS `klient`;
CREATE TABLE IF NOT EXISTS `klient` (
  `n` int NOT NULL AUTO_INCREMENT,
  `fio` varchar(250) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `adr` varchar(500) DEFAULT NULL,
  `nschet` int DEFAULT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `i3` (`fio`),
  UNIQUE KEY `idclient` (`n`) USING BTREE,
  KEY `FKschet` (`nschet`) USING BTREE,
  CONSTRAINT `FKschet` FOREIGN KEY (`nschet`) REFERENCES `schet` (`n`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы dmaslak.klient: ~10 rows (приблизительно)
DELETE FROM `klient`;
/*!40000 ALTER TABLE `klient` DISABLE KEYS */;
INSERT INTO `klient` (`n`, `fio`, `adr`, `nschet`) VALUES
	(1, 'Говрицов А.К.', 'г. Бобруйск, ул. Крылова, 152', 14),
	(2, 'Иванов К.А.', 'г. Минск, ул. Радиальная, 11', 11),
	(3, 'Максимова А.Г.', 'г. Жодино, ул. Неманская, 15-6', 13),
	(4, 'Мавриков П.К.', 'г. Бобруйск, ул. Минская, 14-2', 19),
	(5, 'Парахневич С.А.', 'г. Рогачев, ул. Юбилейная, 23', 12),
	(6, 'Бобр Ю.Н.', 'г. Мозырь, ул.Б.Юности, 68', 15),
	(7, 'Кузьменко Е.В.', 'г.Гомель, ул.Б.Хмельницкого 72 ', 17),
	(8, 'Стаховский В.В.', 'г.Калинковичи, ул.Гастело, 33', 16),
	(9, 'Фещенко В.П.', 'г.Речица, ул.8 марта, 12', 20),
	(10, 'Комисаров Т.В.', 'г.Житковичи, ул.Пушкина,69', 18);
/*!40000 ALTER TABLE `klient` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.nakladnaya
DROP TABLE IF EXISTS `nakladnaya`;
CREATE TABLE IF NOT EXISTS `nakladnaya` (
  `n` int NOT NULL AUTO_INCREMENT,
  `ntovar` int NOT NULL,
  `kolvo` int unsigned NOT NULL,
  `summa` float(12,0) unsigned NOT NULL,
  `nklient` int NOT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `idnaklad` (`n`) USING BTREE,
  KEY `FKtovarn` (`ntovar`) USING BTREE,
  KEY `FK_nakladnaya_klient` (`nklient`) USING BTREE,
  CONSTRAINT `FK_nakladnaya_klient` FOREIGN KEY (`nklient`) REFERENCES `klient` (`n`),
  CONSTRAINT `FKtovarn` FOREIGN KEY (`ntovar`) REFERENCES `tovar` (`n`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Накладные на товар';

-- Дамп данных таблицы dmaslak.nakladnaya: ~5 rows (приблизительно)
DELETE FROM `nakladnaya`;
/*!40000 ALTER TABLE `nakladnaya` DISABLE KEYS */;
INSERT INTO `nakladnaya` (`n`, `ntovar`, `kolvo`, `summa`, `nklient`) VALUES
	(1, 1, 3, 60, 1),
	(2, 2, 5, 100, 2),
	(3, 6, 1, 55, 6),
	(4, 7, 1, 20, 4),
	(5, 10, 5, 55, 7);
/*!40000 ALTER TABLE `nakladnaya` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.postav
DROP TABLE IF EXISTS `postav`;
CREATE TABLE IF NOT EXISTS `postav` (
  `n` int NOT NULL AUTO_INCREMENT,
  `nazv` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `uradr` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `nschet` int DEFAULT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `idpostav` (`n`) USING BTREE,
  UNIQUE KEY `i4` (`nazv`) USING BTREE,
  KEY `FKschetp` (`nschet`) USING BTREE,
  CONSTRAINT `FKschetp` FOREIGN KEY (`nschet`) REFERENCES `schet` (`n`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Поставщики';

-- Дамп данных таблицы dmaslak.postav: ~10 rows (приблизительно)
DELETE FROM `postav`;
/*!40000 ALTER TABLE `postav` DISABLE KEYS */;
INSERT INTO `postav` (`n`, `nazv`, `uradr`, `nschet`) VALUES
	(1, 'ООО СВ-ТрансЛигистик', 'г.Гродно, ул.Суворова,254', 4),
	(2, 'ИП Тишкевич А.Т.', 'г.Полоцк, ул.Советская 22', 3),
	(3, 'ООО СимулПлюс', 'г.Витебск, ул.Ф.Скорины, 59', 5),
	(4, 'ЧТУП Сом-Трак', 'г.Солигорск, ул.Я.Коласа,76', 1),
	(5, 'ЧТУП АксаЛайт', 'г.Брест,ул.Ленина,43', 2),
	(6, 'ОДО Белтехстрой', 'г.Пинск,ул.Советских Пограничников,92', 7),
	(7, 'ООО Горизонт', 'г.Лида,ул.Фолюш,67', 8),
	(8, 'ООО Алтерм', 'г.Новополоцк,ул.Е.Полоцкой,41', 10),
	(9, 'ОДО Белросимпорт', 'г.Мозырь,ул.Мостовая,3', 6),
	(10, 'ЧТУП Комплайт', 'г.Кобрин,ул.Фрунзе,10', 9);
/*!40000 ALTER TABLE `postav` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.schet
DROP TABLE IF EXISTS `schet`;
CREATE TABLE IF NOT EXISTS `schet` (
  `n` int NOT NULL AUTO_INCREMENT,
  `bank` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `numb` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `sost` int NOT NULL DEFAULT '0',
  `data` date NOT NULL,
  `cr` enum('Y','N') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `summa` float(12,0) unsigned DEFAULT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `idschet` (`n`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы dmaslak.schet: ~20 rows (приблизительно)
DELETE FROM `schet`;
/*!40000 ALTER TABLE `schet` DISABLE KEYS */;
INSERT INTO `schet` (`n`, `bank`, `numb`, `sost`, `data`, `cr`, `summa`) VALUES
	(1, 'Паритетбанк', '251485758', 1250, '2020-03-19', '', 8500),
	(2, 'Альфа-Банк', '251452854', 0, '2019-10-23', '', 9520),
	(3, 'ВТББанк', '956256325', 0, '2020-08-12', '', 9000),
	(4, 'Белинвестбанк', '254152889', 200, '2018-02-24', '', 8000),
	(5, 'Белгазпромбанк', '325856984', 0, '2016-09-28', '', 800),
	(6, 'Приорбанк', '233625990', 820, '2017-05-11', '', 1250),
	(7, 'МоскваМинск', '000025215', 0, '2019-09-24', '', 820),
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

-- Дамп структуры для таблица dmaslak.sklad
DROP TABLE IF EXISTS `sklad`;
CREATE TABLE IF NOT EXISTS `sklad` (
  `N` int unsigned NOT NULL AUTO_INCREMENT,
  `adres` varchar(5000) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`N`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы dmaslak.sklad: ~10 rows (приблизительно)
DELETE FROM `sklad`;
/*!40000 ALTER TABLE `sklad` DISABLE KEYS */;
INSERT INTO `sklad` (`N`, `adres`) VALUES
	(1, 'г.Бобруйск,ул. Гоголя,172'),
	(2, 'г. Минск, ул. Ленина,5-2'),
	(3, 'г.Гомель, ул. М.Хмельницкого,125'),
	(4, 'г. Бобруйск, ул. Крылова,15-32'),
	(5, 'г. Могилев, пл. Ленина, 14'),
	(6, 'г.Мозырь, ул.Фрунзе, 7'),
	(7, 'г.Новоплоцк, ул.Социалистическая 7'),
	(8, 'г.Витебск, ул.50 лет СССР'),
	(9, 'г.Солигорск, ул.Рябиновая 7'),
	(10, 'г.Гродно, ул.Комунальная 16');
/*!40000 ALTER TABLE `sklad` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.tovar
DROP TABLE IF EXISTS `tovar`;
CREATE TABLE IF NOT EXISTS `tovar` (
  `n` int NOT NULL AUTO_INCREMENT,
  `name` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `ed` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `cena` int unsigned NOT NULL,
  `npostav` int NOT NULL,
  `nsklad` int unsigned NOT NULL,
  `Kolvo` int unsigned NOT NULL,
  `sort` int unsigned NOT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `idtovar` (`n`) USING BTREE,
  KEY `FKpostavt` (`npostav`) USING BTREE,
  KEY `FK_tovar_sklad` (`nsklad`) USING BTREE,
  KEY `i5` (`name`) USING BTREE,
  CONSTRAINT `FK_tovar_sklad` FOREIGN KEY (`nsklad`) REFERENCES `sklad` (`N`),
  CONSTRAINT `FKpostavt` FOREIGN KEY (`npostav`) REFERENCES `postav` (`n`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Список товаров нормализованный';

-- Дамп данных таблицы dmaslak.tovar: ~10 rows (приблизительно)
DELETE FROM `tovar`;
/*!40000 ALTER TABLE `tovar` DISABLE KEYS */;
INSERT INTO `tovar` (`n`, `name`, `ed`, `cena`, `npostav`, `nsklad`, `Kolvo`, `sort`) VALUES
	(1, 'Ноутбук', 'шт', 1499, 1, 1, 28, 0),
	(2, 'Игровая приставка', 'шт', 2455, 2, 1, 21, 0),
	(3, 'Мышка', 'шт', 15, 1, 2, 16, 2),
	(4, 'Фен', 'шт', 59, 2, 2, 4, 1),
	(5, 'Телвизор', 'шт', 4500, 1, 2, 5, 3),
	(6, 'Обогреватель', 'шт', 100, 4, 1, 15, 2),
	(7, 'Чайник', 'шт', 40, 6, 4, 100, 3),
	(8, 'Монитор', 'шт', 700, 7, 3, 50, 2),
	(9, 'Телефон', 'шт', 500, 4, 2, 500, 1),
	(10, 'Миксер', 'шт', 55, 6, 3, 1000, 2);
/*!40000 ALTER TABLE `tovar` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.transport
DROP TABLE IF EXISTS `transport`;
CREATE TABLE IF NOT EXISTS `transport` (
  `n` int NOT NULL AUTO_INCREMENT,
  `nomer` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `marka` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `gruz` float(12,0) NOT NULL,
  `god` int NOT NULL,
  `fio` varchar(150) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `data` date NOT NULL,
  `nsklad` int unsigned NOT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `i5` (`nomer`),
  KEY `FK_transport_sklad` (`nsklad`),
  CONSTRAINT `FK_transport_sklad` FOREIGN KEY (`nsklad`) REFERENCES `sklad` (`N`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы dmaslak.transport: ~6 rows (приблизительно)
DELETE FROM `transport`;
/*!40000 ALTER TABLE `transport` DISABLE KEYS */;
INSERT INTO `transport` (`n`, `nomer`, `marka`, `gruz`, `god`, `fio`, `data`, `nsklad`) VALUES
	(2, 'AI 5215-6', 'MAN', 24000, 2011, 'ПАС-Транс', '2020-11-26', 4),
	(3, 'AM 2532-6', 'DAF', 15000, 2018, 'ПАС-Транс', '2020-12-11', 8),
	(4, 'AK 1256-6', 'DAF', 24000, 2019, 'Ивашин А.С.', '2021-01-29', 1),
	(5, 'AI 6326-6', 'Volvo', 10000, 2010, 'ПАС-Транс', '2021-03-25', 5),
	(6, 'AY 6212-3', 'Iveco', 15000, 2012, 'ПАС-Транс', '2021-02-17', 6),
	(7, 'AR 8967-7', 'Mercedes-benz', 8000, 2017, 'ПАС-Транс', '2021-04-20', 2);
/*!40000 ALTER TABLE `transport` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.zakaz
DROP TABLE IF EXISTS `zakaz`;
CREATE TABLE IF NOT EXISTS `zakaz` (
  `n` int NOT NULL AUTO_INCREMENT,
  `data` date NOT NULL,
  `nclient` int NOT NULL,
  `ntovar` int NOT NULL,
  `kolvo` int NOT NULL DEFAULT '0',
  `cena` float(12,0) NOT NULL,
  `summa` float(12,0) NOT NULL,
  `opl` enum('Y','N') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `id_zakaz` (`n`) USING BTREE,
  KEY `FKtovar` (`ntovar`) USING BTREE,
  KEY `FKclientz` (`nclient`) USING BTREE,
  CONSTRAINT `FKclientz` FOREIGN KEY (`nclient`) REFERENCES `klient` (`n`),
  CONSTRAINT `FKtovar` FOREIGN KEY (`ntovar`) REFERENCES `tovar` (`n`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Список заказов п 10';

-- Дамп данных таблицы dmaslak.zakaz: ~4 rows (приблизительно)
DELETE FROM `zakaz`;
/*!40000 ALTER TABLE `zakaz` DISABLE KEYS */;
INSERT INTO `zakaz` (`n`, `data`, `nclient`, `ntovar`, `kolvo`, `cena`, `summa`, `opl`) VALUES
	(1, '2021-05-19', 2, 2, 3, 2300, 6900, ''),
	(2, '2021-05-19', 4, 3, 1, 520, 520, ''),
	(3, '2021-05-22', 5, 3, 1, 5890, 5890, ''),
	(4, '2019-03-16', 6, 6, 1, 789, 678, '');
/*!40000 ALTER TABLE `zakaz` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;

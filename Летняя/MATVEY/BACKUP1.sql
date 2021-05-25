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

-- Дамп структуры для таблица matvey.firma
DROP TABLE IF EXISTS `firma`;
CREATE TABLE IF NOT EXISTS `firma` (
  `id` int NOT NULL AUTO_INCREMENT,
  `nazvan` varchar(500) NOT NULL DEFAULT '',
  `uradr` varchar(500) NOT NULL DEFAULT '',
  `phone` varchar(50) NOT NULL DEFAULT '',
  `schet` int NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idf` (`id`),
  KEY `FKschetf` (`schet`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Описание';

-- Дамп данных таблицы matvey.firma: ~0 rows (приблизительно)
DELETE FROM `firma`;
/*!40000 ALTER TABLE `firma` DISABLE KEYS */;
INSERT INTO `firma` (`id`, `nazvan`, `uradr`, `phone`, `schet`) VALUES
	(1, 'Инспектор гаджет', 'Ул. Красноармейская д.4а', '+375336512162', 1);
/*!40000 ALTER TABLE `firma` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.kadr
DROP TABLE IF EXISTS `kadr`;
CREATE TABLE IF NOT EXISTS `kadr` (
  `id` int NOT NULL AUTO_INCREMENT,
  `fio` varchar(250) NOT NULL,
  `dolg` varchar(500) NOT NULL,
  `obraz` varchar(500) NOT NULL,
  `salary` float NOT NULL,
  `data` date NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idk` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Сотрудники';

-- Дамп данных таблицы matvey.kadr: ~5 rows (приблизительно)
DELETE FROM `kadr`;
/*!40000 ALTER TABLE `kadr` DISABLE KEYS */;
INSERT INTO `kadr` (`id`, `fio`, `dolg`, `obraz`, `salary`, `data`) VALUES
	(1, 'Иванов А.С.', 'Директор', 'Высшее', 945, '2018-02-20'),
	(2, 'Аверкова И.В.', 'Бухгалтер', 'Высшее', 750, '2018-02-20'),
	(3, 'Долбик К.В.', 'Водитель', 'Среднее-специальное', 550, '2020-02-20'),
	(4, 'Савицкий А.Н.', 'Менеджер ', 'Среднее-специальное', 600, '2020-02-20'),
	(5, 'Зарянина Т.Н.', 'Продавец', 'Среднее-специальное', 550, '2020-02-20');
/*!40000 ALTER TABLE `kadr` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.klient1
DROP TABLE IF EXISTS `klient`;
CREATE TABLE IF NOT EXISTS `klient` (
  `id` int NOT NULL AUTO_INCREMENT,
  `nazv` varchar(250) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `uradr` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `idschet` int DEFAULT NULL,
  `tip` int DEFAULT '0',
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE KEY `idc` (`id`) USING BTREE,
  KEY `FtKschet` (`id`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;

-- Дамп данных таблицы matvey.klient1: ~20 rows (приблизительно)
DELETE FROM `klient`;
/*!40000 ALTER TABLE `klient` DISABLE KEYS */;
INSERT INTO `klient` (`id`, `nazv`, `uradr`, `idschet`, `tip`) VALUES
	(1, 'Говрицов А.К.', 'г. Бобруйск, ул. Крылова, 152', 5, 0),
	(2, 'Иванов К.А.', 'г. Минск, ул. Радиальная, 11', 6, 0),
	(3, 'Максимова А.Г.', 'г. Жодино, ул. Неманская, 15-6', 7, 0),
	(4, 'Мавриков П.К.', 'г. Бобруйск, ул. Минская, 14-2', 2, 0),
	(5, 'Парахневич С.А.', 'г. Рогачев, ул. Юбилейная, 23', 6, 0),
	(6, 'Бобр Ю.Н.', 'г.Мозырь ул.Б.Юности 68', 5, 0),
	(7, 'Кузьменко Е.В.', 'г. Гомель ул. Б.Хмельницкого 72', 1, 0),
	(8, 'Стаховский В.В.', 'г. Калинковичи ул.Гастело 33', 4, 0),
	(9, 'Фещенко В.П.', 'г. Речица ул. 8 марта', 3, 0),
	(10, 'Комиссаров Т.В.', 'г.Житковичи ул.Пушкина 69', 2, 0);
/*!40000 ALTER TABLE `klient` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.naklad
DROP TABLE IF EXISTS `naklad`;
CREATE TABLE IF NOT EXISTS `naklad` (
  `idnakladnaya` int NOT NULL AUTO_INCREMENT,
  `idtovar` int NOT NULL,
  `kolvo` int NOT NULL,
  `summa` float NOT NULL,
  `idklient` int NOT NULL,
  PRIMARY KEY (`idnakladnaya`),
  UNIQUE KEY `idnaklad` (`idnakladnaya`),
  KEY `FKtovarn` (`idtovar`),
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Накладные на товар';

-- Дамп данных таблицы matvey.naklad: ~2 rows (приблизительно)
DELETE FROM `naklad`;
/*!40000 ALTER TABLE `naklad` DISABLE KEYS */;
INSERT INTO `naklad` (`idnakladnaya`, `idtovar`, `kolvo`, `summa`, `idklient`) VALUES
	(1, 1, 3, 60, 1),
	(2, 2, 5, 100, 2);
/*!40000 ALTER TABLE `naklad` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.postav1
DROP TABLE IF EXISTS `postav`;
CREATE TABLE IF NOT EXISTS `postav` (
  `id` int NOT NULL AUTO_INCREMENT,
  `nazv` varchar(250) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `uradr` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `idschet` int NOT NULL,
  `tip` int DEFAULT '1',
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE KEY `idc` (`id`) USING BTREE,
  KEY `FtKschet` (`id`) USING BTREE,
  KEY `FKschet` (`idschet`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;

-- Дамп данных таблицы matvey.postav1: ~20 rows (приблизительно)
DELETE FROM `postav`;
/*!40000 ALTER TABLE `postav` DISABLE KEYS */;
INSERT INTO `postav1` (`id`, `nazv`, `uradr`, `idschet`, `tip`) VALUES
	(12, 'ИП Тишкевич А.Т.', 'г.Полоцк ул. Советская 22', 3, 1),
	(13, 'ООО СимулПлюс', 'г. Витебск ул. Ф.Скорины 59', 2, 1),
	(14, 'ЧТУП Сом-Трак', 'г. Солигорск ул. Я.Коласа 76', 3, 1),
	(15, 'ЧТУП АксаЛайт', 'г. Брест ул. Ленина 43', 2, 1),
	(16, 'ОДО Белтехстрой', 'г. Пинск ул. Советских пограничников 92', 5, 1),
	(17, 'ООО Алтерм', 'г.Лида ул. Фолюш 67', 2, 1),
	(18, 'ООО Горизонт', 'г. Новополоцк ул. Е.Полоцкой 41', 6, 1),
	(19, 'ПУ Мозырьгаз', 'г. Мозырь ул. Мостовая 3', 3, 1),
	(20, 'ОДО Белросимпортстрой', 'г. Кобрин ул. Фрунзе 10', 4, 1);
/*!40000 ALTER TABLE `postav` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.schet
DROP TABLE IF EXISTS `schet`;
CREATE TABLE IF NOT EXISTS `schet` (
  `id` int NOT NULL AUTO_INCREMENT,
  `bank` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `numchet` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `status` int NOT NULL DEFAULT '0',
  `data` date NOT NULL,
  `creditstat` int NOT NULL DEFAULT '0',
  `creditsum` float NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idt` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы matvey.schet: ~7 rows (приблизительно)
DELETE FROM `schet`;
/*!40000 ALTER TABLE `schet` DISABLE KEYS */;
INSERT INTO `schet` (`id`, `bank`, `numchet`, `status`, `data`, `creditstat`, `creditsum`) VALUES
	(1, 'Паритетбанк', '251485758', 1250, '2020-05-19', 1250, 8500),
	(2, 'Альфа-Банк', '251452854', 0, '2021-05-19', 0, 9520),
	(3, 'ВТББанк', '956256325', 0, '2021-05-19', 0, 9000),
	(4, 'Белгазпромбанк', '254152889', 200, '2021-05-19', 200, 8000),
	(5, 'Белинвестбанк', '325856984', 0, '2021-05-19', 0, 800),
	(6, 'Приорбанк', '233625990', 820, '2021-05-19', 820, 1250),
	(7, 'МоскваМинск', '000025215', 0, '2021-05-19', 0, 820);
/*!40000 ALTER TABLE `schet` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.sklad
DROP TABLE IF EXISTS `sklad`;
CREATE TABLE IF NOT EXISTS `sklad` (
  `Nsklad` int unsigned NOT NULL AUTO_INCREMENT,
  `adress` varchar(5000) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `naimen` varchar(500) NOT NULL,
  PRIMARY KEY (`Nsklad`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы matvey.sklad: ~5 rows (приблизительно)
DELETE FROM `sklad`;
/*!40000 ALTER TABLE `sklad` DISABLE KEYS */;
INSERT INTO `sklad` (`Nsklad`, `adress`, `naimen`) VALUES
	(1, 'г.Бобруйск,ул. Гоголя,172', 'Бобр Гоголя'),
	(2, 'г. Минск, ул. Ленина,5-2', 'Минск'),
	(3, 'г.Гомель, ул. Б.Хмельницкого,125', 'Гомель'),
	(4, 'г. Бобруйск, ул. Крылова,15-32', 'Бобр Крылова'),
	(5, 'г. Могилев, пл. Ленина, 14', 'Могилев');
/*!40000 ALTER TABLE `sklad` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.tovar
DROP TABLE IF EXISTS `tovar`;
CREATE TABLE IF NOT EXISTS `tovar` (
  `idtovar` int NOT NULL AUTO_INCREMENT,
  `naimen_tovara` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `ed_izm` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `cena` int NOT NULL,
  `idpostav` int NOT NULL,
  `sklad` int unsigned NOT NULL,
  `Kolvo` int NOT NULL,
  `sort` int NOT NULL,
  PRIMARY KEY (`idtovar`),
  UNIQUE KEY `idtovar` (`idtovar`),
  KEY `FKpostavt` (`idpostav`),
  KEY `FK_tovar_sklad` (`sklad`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Список товаров нормализованный';

-- Дамп данных таблицы matvey.tovar: ~6 rows (приблизительно)
DELETE FROM `tovar`;
/*!40000 ALTER TABLE `tovar` DISABLE KEYS */;
INSERT INTO `tovar` (`idtovar`, `naimen_tovara`, `ed_izm`, `cena`, `idpostav`, `sklad`, `Kolvo`, `sort`) VALUES
	(1, 'Ноутбук', 'шт', 1499, 1, 1, 28, 0),
	(2, 'Игровая приставка Xbox', 'шт', 2455, 2, 1, 21, 0),
	(3, 'Клавиатура', 'шт', 15, 1, 2, 16, 0),
	(4, 'Фен', 'шт', 59, 2, 2, 4, 0),
	(5, 'Телвизор', 'шт', 4500, 1, 2, 5, 0),
	(6, 'Мышка', 'шт', 10, 4, 1, 10, 0);
/*!40000 ALTER TABLE `tovar` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.transp
DROP TABLE IF EXISTS `transp`;
CREATE TABLE IF NOT EXISTS `transp` (
  `idtransport` int NOT NULL AUTO_INCREMENT,
  `nom_auto` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `marka_auto` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `tonnag` float NOT NULL,
  `god_vipuska` int NOT NULL,
  `vladelec` varchar(450) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `data_perevozki` date DEFAULT NULL,
  `nsklad` int unsigned DEFAULT NULL,
  PRIMARY KEY (`idtransport`) USING BTREE,
  KEY `FK_transport_sklad` (`nsklad`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы matvey.transp: ~4 rows (приблизительно)
DELETE FROM `transp`;
/*!40000 ALTER TABLE `transp` DISABLE KEYS */;
INSERT INTO `transp` (`idtransport`, `nom_auto`, `marka_auto`, `tonnag`, `god_vipuska`, `vladelec`, `data_perevozki`, `nsklad`) VALUES
	(2, 'AI 5215-6', 'MAN', 24000, 2011, 'ПАС-Транс', NULL, NULL),
	(3, 'AM 2532-6', 'DAF', 15000, 2018, 'ПАС-Транс', NULL, NULL),
	(4, 'AK 1256-6', 'DAF', 24000, 2019, 'ПАС-Транс', NULL, NULL),
	(5, 'AI 6326-6', 'Volvo', 10000, 2010, 'ПАС-Транс', NULL, NULL);
/*!40000 ALTER TABLE `transp` ENABLE KEYS */;

-- Дамп структуры для таблица matvey.zakaz
DROP TABLE IF EXISTS `zakaz`;
CREATE TABLE IF NOT EXISTS `zakaz` (
  `id_zakaz` int NOT NULL AUTO_INCREMENT,
  `data` date DEFAULT NULL,
  `id_client` int NOT NULL,
  `id_tovar` int NOT NULL,
  `kol_vo_zak_tov` int NOT NULL DEFAULT '0',
  `cena_tovara` float NOT NULL,
  `sum_zakaza` float NOT NULL,
  PRIMARY KEY (`id_zakaz`),
  UNIQUE KEY `id_zakaz` (`id_zakaz`),
  KEY `FKtovar` (`id_tovar`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Список заказов п 10';

-- Дамп данных таблицы matvey.zakaz: ~3 rows (приблизительно)
DELETE FROM `zakaz`;
/*!40000 ALTER TABLE `zakaz` DISABLE KEYS */;
INSERT INTO `zakaz` (`id_zakaz`, `data`, `id_client`, `id_tovar`, `kol_vo_zak_tov`, `cena_tovara`, `sum_zakaza`) VALUES
	(1, '2021-05-19', 2, 2, 3, 2300, 6900),
	(2, '2021-05-19', 4, 3, 1, 520, 520),
	(3, '2021-05-22', 5, 3, 1, 5890, 5890);
/*!40000 ALTER TABLE `zakaz` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;

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

-- Дамп данных таблицы b_01_21_09.avt_01_21_09: ~0 rows (приблизительно)
DELETE FROM `avt_01_21_09`;
/*!40000 ALTER TABLE `avt_01_21_09` DISABLE KEYS */;
INSERT INTO `avt_01_21_09` (`avt_id`, `a_firstname`, `a_lastname`, `birthd`, `sex`, `town`) VALUES
	(1, 'Сергей', 'Иванов', '1940-06-08', 'М', 1),
	(2, 'Андрей', 'Петров', '1950-06-08', 'М', 2),
	(3, 'Василий', 'Сидоров', '1960-06-08', 'М', 1),
	(4, 'Николай', 'Лукьянов', '1970-06-08', 'Ж', 2),
	(5, 'Петр', 'Григорьев', '1980-06-08', 'Ж', 3),
	(6, 'Николай', 'Митрофанов', '1990-06-08', 'Ж', 4),
	(7, 'Андрей', 'Степанов', '1980-06-08', 'М', 3),
	(8, 'Иван', 'Федорцов', '1970-06-08', 'М', 4),
	(9, 'Сергей', 'Кешкин', '1960-06-08', 'Ж', 3);
/*!40000 ALTER TABLE `avt_01_21_09` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;

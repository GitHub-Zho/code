/*
Navicat MySQL Data Transfer

Source Server         : 23e
Source Server Version : 80026
Source Host           : localhost:3306
Source Database       : mybase

Target Server Type    : MYSQL
Target Server Version : 80026
File Encoding         : 65001

Date: 2021-09-11 18:24:58
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for flight
-- ----------------------------
DROP TABLE IF EXISTS `flight`;
CREATE TABLE `flight` (
  `number` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `company` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `planetype` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `startplace` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `endplace` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `starttime` datetime DEFAULT NULL,
  `endtime` datetime DEFAULT NULL,
  `flyingtime` int DEFAULT NULL,
  `pilotone` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `pilottwo` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `ticketselled` int DEFAULT '0',
  `seat1` int DEFAULT NULL,
  `seat1rest` int DEFAULT NULL,
  `seatprice1` int DEFAULT NULL,
  `seat2` int DEFAULT NULL,
  `seat2rest` int DEFAULT NULL,
  `seatprice2` int DEFAULT NULL,
  `seat3` int DEFAULT NULL,
  `seat3rest` int DEFAULT NULL,
  `seatprice3` int DEFAULT NULL,
  `setoff` enum('true','false') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT 'false',
  `ontimerate` char(4) DEFAULT NULL,
  `onseatrate` float(6,1) DEFAULT '0.0',
  `sumprice` int DEFAULT '0',
  PRIMARY KEY (`number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of flight
-- ----------------------------
INSERT INTO `flight` VALUES ('AB1456', '中国国航', '波音 789-9', '昆明', '思茅', '2021-10-11 00:00:00', '2021-10-12 00:00:00', '60', '01', '02', '1', '150', '150', '1100', '150', '149', '1200', '150', '150', '1300', 'true', '98%', '0.0', '2400');
INSERT INTO `flight` VALUES ('AD1234', '中国国航', '波音 789-9', '昆明', '杭州', '2021-10-01 00:00:00', '2021-10-02 00:00:00', '24', '19', '09', '3', '229', '229', '213', '131', '130', '1313', '131', '129', '131', 'true', '98%', '0.0', '786');
INSERT INTO `flight` VALUES ('CZ3128', '东方航空', '空客320', '北京', '长沙', '2021-08-13 20:00:00', '2021-08-13 23:00:00', '180', '15', '12', '440', '150', '2', '2993', '150', '2', '1329', '150', '6', '841', 'true', '66%', '1.0', '145255');
INSERT INTO `flight` VALUES ('CZ3148', '中国国航', '空客A330-300', '北京', '北海', '2021-09-17 20:00:00', '2021-08-14 01:00:00', '300', '35', '25', '727', '255', '13', '2568', '255', '13', '1475', '255', '12', '730', 'true', '64%', '1.0', '19025');
INSERT INTO `flight` VALUES ('CZ3193', '南方航空', '空客320', '呼和浩特', '满洲里', '2021-08-13 14:00:00', '2021-08-13 16:00:00', '120', '30', '18', '640', '150', '3', '2537', '150', '4', '1613', '150', '0', '985', 'true', '63%', '0.9', '4225234');
INSERT INTO `flight` VALUES ('CZ3235', '东方航空', '空客A330-300', '桂林', '广州', '2021-08-29 09:00:00', '2021-08-30 10:00:00', '60', '13', '12', '254', '255', '14', '2161', '255', '16', '1160', '255', '12', '892', 'true', '56%', '0.3', '235127');
INSERT INTO `flight` VALUES ('CZ3253', '南方航空', '波音737', '桂林', '南京', '2021-08-30 08:00:00', '2021-08-13 09:00:00', '60', '22', '8', '347', '120', '3', '2444', '120', '4', '1807', '120', '3', '849', 'true', '82%', '1.0', '238740');
INSERT INTO `flight` VALUES ('CZ3297', '中国国航', '波音 789-9', '南宁', '广州', '2021-08-31 16:00:00', '2021-08-31 17:00:00', '60', '16', '7', '684', '229', '30', '2007', '229', '30', '1903', '229', '29', '766', 'true', '96%', '0.7', '354366');
INSERT INTO `flight` VALUES ('CZ3304', '东方航空', '空客A330-300', '桂林', '广州', '2021-09-28 16:00:00', '2021-09-29 17:00:00', '60', '12', '35', '433', '255', '14', '2194', '255', '14', '1968', '255', '14', '853', 'true', '76%', '0.8', '457674');
INSERT INTO `flight` VALUES ('CZ3423', '南方航空', '空客320', '贵阳', '昆明', '2021-09-30 19:00:00', '2021-09-30 20:00:00', '60', '25', '23', '345', '150', '3', '2212', '150', '4', '1953', '150', '4', '801', 'true', '94%', '0.7', '345345');
INSERT INTO `flight` VALUES ('CZ3450', '中国国航', '空客A330-300', '昆明', '广州', '2021-10-21 20:00:00', '2021-10-21 22:00:00', '120', '22', '31', '366', '255', '14', '2996', '255', '14', '1092', '255', '15', '920', 'true', '86%', '0.5', '634745');
INSERT INTO `flight` VALUES ('CZ3488', '中国国航', '空客A330-300', '昆明', '广州', '2021-08-14 18:00:00', '2021-08-14 20:00:00', '120', '29', '20', '256', '255', '14', '2810', '255', '14', '1037', '255', '14', '733', 'true', '64%', '0.7', '758543');
INSERT INTO `flight` VALUES ('CZ3490', '中国国航', '空客A330-300', '昆明', '广州', '2021-08-14 22:00:00', '2021-08-14 23:00:00', '60', '39', '34', '346', '255', '14', '2294', '255', '14', '1401', '255', '14', '770', 'true', '63%', '0.6', '346573');
INSERT INTO `flight` VALUES ('CZ3512', '东方航空', '空客320', '杭州', '广州', '2021-08-13 16:00:00', '2021-08-13 18:00:00', '120', '35', '29', '685', '150', '3', '2333', '150', '3', '1598', '150', '3', '913', 'true', '56%', '0.7', '346364');
INSERT INTO `flight` VALUES ('CZ3548', '东方航空', '空客A330-300', '上海虹桥', '广州', '2021-09-23 09:00:00', '2021-09-23 00:00:00', '900', '39', '39', '433', '255', '14', '2389', '255', '14', '1488', '255', '14', '904', 'true', '82%', '0.7', '58325');
INSERT INTO `flight` VALUES ('CZ3663', '中国国航', '波音 789-9', '广州', '北海', '2021-08-13 11:00:00', '2021-08-14 00:00:00', '780', '21', '18', '346', '229', '30', '2586', '229', '30', '1602', '229', '30', '842', 'true', '82%', '0.6', '457565');
INSERT INTO `flight` VALUES ('CZ3709', '南方航空', '空客320', '长沙', '银川', '2021-09-21 08:00:00', '2021-09-21 11:00:00', '180', '39', '33', '684', '150', '3', '2055', '150', '4', '1095', '150', '4', '968', 'true', '96%', '0.7', '256723');
INSERT INTO `flight` VALUES ('CZ3764', '中国国航', '波音 789-9', '温州', '广州', '2021-08-14 14:00:00', '2021-08-14 15:00:00', '60', '11', '19', '432', '229', '30', '2478', '229', '31', '1502', '229', '30', '985', 'true', '76%', '0.8', '45746');
INSERT INTO `flight` VALUES ('CZ3775', '东方航空', '空客320', '广州', '宁波', '2021-08-13 15:00:00', '2021-08-13 17:00:00', '120', '25', '14', '256', '150', '3', '2865', '150', '4', '1060', '150', '4', '750', 'true', '94%', '0.5', '345345');
INSERT INTO `flight` VALUES ('CZ3788', '中国国航', '空客A330-300', '哈尔滨', '广州', '2021-08-14 16:00:00', '2021-08-14 21:00:00', '300', '25', '22', '346', '255', '14', '2111', '255', '14', '1208', '255', '14', '675', 'true', '86%', '1.0', '634745');
INSERT INTO `flight` VALUES ('CZ3810', '中国国航', '波音 789-9', '温州', '广州', '2021-08-14 20:00:00', '2021-08-14 22:00:00', '120', '17', '39', '684', '229', '30', '2502', '229', '30', '1130', '229', '30', '937', 'true', '64%', '0.9', '758543');
INSERT INTO `flight` VALUES ('CZ3818', '中国国航', '波音 789-9', '合肥', '广州', '2021-08-14 19:00:00', '2021-08-14 21:00:00', '120', '24', '26', '433', '229', '30', '2882', '229', '30', '1733', '229', '30', '668', 'true', '63%', '0.8', '346573');
INSERT INTO `flight` VALUES ('CZ3871', '南方航空', '波音737', '广州', '南京', '2021-08-13 21:00:00', '2021-08-13 23:00:00', '120', '28', '28', '346', '120', '3', '2269', '120', '4', '1530', '120', '4', '678', 'true', '56%', '1.0', '346364');
INSERT INTO `flight` VALUES ('CZ3875', '中国国航', '波音 789-9', '厦门', '深圳', '2021-08-14 00:00:00', '2021-08-14 13:00:00', '780', '25', '37', '684', '229', '30', '2977', '229', '30', '1941', '229', '30', '898', 'true', '82%', '0.8', '58325');
INSERT INTO `flight` VALUES ('CZ3899', '东方航空', '空客A330-300', '广州', '常州', '2021-08-13 08:00:00', '2021-08-13 11:00:00', '180', '35', '10', '430', '255', '14', '2590', '255', '16', '1543', '255', '15', '859', 'true', '96%', '0.6', '456723');
INSERT INTO `flight` VALUES ('CZ5017', '中国国航', '波音 789-9', '西安', '北京', '2021-08-14 21:00:00', '2021-08-14 23:00:00', '120', '39', '26', '345', '229', '30', '2575', '229', '30', '1346', '229', '30', '929', 'true', '63%', '0.7', '235235');
INSERT INTO `flight` VALUES ('CZ5053', '中国国航', '波音 789-9', '昆明', '北京', '2021-08-14 16:00:00', '2021-08-14 19:00:00', '180', '14', '40', '367', '229', '30', '2664', '229', '30', '1346', '229', '30', '799', 'true', '56%', '0.7', '354366');
INSERT INTO `flight` VALUES ('CZ5138', '中国国航', '波音 789-9', '南京', '昆明', '2021-08-14 00:00:00', '2021-08-14 15:00:00', '900', '34', '20', '256', '229', '30', '2745', '229', '30', '1614', '229', '30', '852', 'true', '82%', '0.9', '457674');
INSERT INTO `flight` VALUES ('CZ5275', '南方航空', '波音737', '成都', '西安', '2021-08-13 11:00:00', '2021-08-14 00:00:00', '780', '39', '11', '346', '120', '3', '2037', '120', '4', '1324', '120', '4', '863', 'true', '82%', '0.5', '345345');
INSERT INTO `flight` VALUES ('CZ5347', '南方航空', '空客320', '广州', '温州', '2021-08-13 11:00:00', '2021-08-13 13:00:00', '120', '30', '6', '685', '150', '3', '2486', '150', '4', '1804', '150', '3', '608', 'true', '96%', '0.7', '634745');
INSERT INTO `flight` VALUES ('CZ5357', '东方航空', '空客A330-300', '杭州', '广州', '2021-08-13 10:00:00', '2021-08-14 00:00:00', '840', '20', '21', '433', '255', '14', '2916', '255', '14', '1936', '255', '14', '778', 'false', '76%', '0.7', '758543');
INSERT INTO `flight` VALUES ('CZ5415', '中国国航', '波音 789-9', '西安', '北京', '2021-08-14 16:00:00', '2021-08-14 18:00:00', '120', '11', '9', '345', '229', '30', '2014', '229', '30', '1891', '229', '30', '888', 'true', '94%', '0.9', '346573');
INSERT INTO `flight` VALUES ('CZ5454', '南方航空', '波音737', '北京', '武汉', '2021-08-13 17:00:00', '2021-08-13 19:00:00', '120', '13', '30', '256', '120', '3', '4360', '120', '4', '1726', '120', '4', '940', 'false', '86%', '0.5', '346364');
INSERT INTO `flight` VALUES ('CZ5545', '中国国航', '波音 789-9', '昆明', '杭州', '2021-08-14 00:00:00', '2021-08-14 14:00:00', '840', '22', '21', '346', '229', '30', '2199', '229', '30', '1512', '229', '30', '720', 'false', '64%', '1.0', '58325');
INSERT INTO `flight` VALUES ('CZ5594', '中国国航', '波音 789-9', '思茅', '昆明', '2021-08-14 14:00:00', '2021-08-14 15:00:00', '60', '19', '22', '684', '229', '30', '2708', '229', '30', '1885', '229', '30', '686', 'false', '63%', '0.8', '456723');
INSERT INTO `flight` VALUES ('CZ5802', '东方航空', '空客320', '北京', '长沙', '2021-08-13 22:00:00', '2021-08-14 00:00:00', '120', '36', '17', '433', '150', '3', '2254', '150', '4', '1976', '150', '4', '780', 'false', '56%', '0.5', '256723');
INSERT INTO `flight` VALUES ('CZ6227', '中国国航', '波音 789-9', '郑州', '呼和浩特', '2021-08-14 08:00:00', '2021-08-14 09:00:00', '60', '22', '13', '346', '229', '30', '2227', '229', '30', '1463', '229', '30', '957', 'true', '63%', '1.0', '45746');
INSERT INTO `flight` VALUES ('CZ6261', '东方航空', '空客A330-300', '哈尔滨', '广州', '2021-08-13 09:00:00', '2021-08-13 15:00:00', '360', '28', '10', '684', '255', '14', '2909', '255', '14', '1343', '255', '14', '770', 'false', '56%', '0.9', '345345');
INSERT INTO `flight` VALUES ('CZ6273', '南方航空', '空客320', '哈尔滨', '深圳', '2021-08-13 08:00:00', '2021-08-13 15:00:00', '420', '27', '14', '433', '150', '3', '2164', '150', '4', '1367', '150', '4', '954', 'true', '82%', '0.7', '235235');
INSERT INTO `flight` VALUES ('CZ6279', '中国国航', '波音 789-9', '哈尔滨', '漠河', '2021-08-14 13:00:00', '2021-08-14 15:00:00', '120', '18', '13', '345', '229', '30', '2269', '229', '30', '1510', '229', '30', '842', 'true', '96%', '0.8', '354366');
INSERT INTO `flight` VALUES ('CZ6285', '南方航空', '波音737', '济南', '乌鲁木齐', '2021-08-13 11:00:00', '2021-08-13 15:00:00', '240', '27', '29', '367', '120', '3', '3049', '120', '4', '1889', '120', '4', '470', 'false', '63%', '0.6', '457674');
INSERT INTO `flight` VALUES ('CZ6312', '南方航空', '波音737', '青岛', '沈阳', '2021-08-13 18:00:00', '2021-08-13 19:00:00', '60', '18', '37', '256', '120', '3', '2697', '120', '4', '1967', '120', '4', '887', 'false', '56%', '0.7', '345345');
INSERT INTO `flight` VALUES ('CZ6321', '南方航空', '空客320', '大连', '广州', '2021-08-13 08:00:00', '2021-08-13 11:00:00', '180', '26', '29', '346', '150', '3', '2410', '150', '4', '1348', '150', '4', '697', 'false', '63%', '0.8', '634745');
INSERT INTO `flight` VALUES ('CZ6399', '南方航空', '波音737', '北京', '武汉', '2021-08-13 07:00:00', '2021-08-13 09:00:00', '120', '24', '22', '684', '120', '3', '4360', '120', '4', '1359', '120', '4', '908', 'false', '56%', '0.7', '758543');
INSERT INTO `flight` VALUES ('CZ6403', '中国国航', '波音 789-9', '沈阳', '重庆', '2021-08-14 08:00:00', '2021-08-14 11:00:00', '180', '22', '22', '433', '229', '229', '2419', '229', '229', '1008', '229', '229', '949', 'true', '82%', '0.6', '346573');
INSERT INTO `flight` VALUES ('CZ6404', '中国国航', '空客A330-300', '昆明', '重庆', '2021-08-14 15:00:00', '2021-08-14 16:00:00', '60', '37', '4', '345', '255', '14', '2934', '255', '14', '1042', '255', '14', '604', 'true', '96%', '0.7', '346364');
INSERT INTO `flight` VALUES ('CZ6426', '南方航空', '波音737', '昆明', '大连', '2021-08-13 13:00:00', '2021-08-13 18:00:00', '300', '34', '20', '256', '120', '3', '2676', '120', '4', '1093', '120', '4', '794', 'true', '63%', '0.8', '58325');
INSERT INTO `flight` VALUES ('CZ6428', '南方航空', '波音737', '昆明', '大连', '2021-08-13 17:00:00', '2021-08-13 23:00:00', '360', '20', '2', '346', '120', '3', '2084', '120', '4', '1693', '120', '4', '990', 'true', '56%', '0.5', '456723');
INSERT INTO `flight` VALUES ('CZ6455', '东方航空', '空客A330-300', '沈阳', '包头', '2021-08-13 07:00:00', '2021-08-13 09:00:00', '120', '35', '5', '684', '255', '14', '2237', '255', '14', '1192', '255', '14', '850', 'true', '82%', '1.0', '256723');
INSERT INTO `flight` VALUES ('CZ6483', '南方航空', '波音737', '沈阳', '三亚', '2021-08-13 08:00:00', '2021-08-13 14:00:00', '360', '11', '37', '433', '120', '3', '2316', '120', '4', '1245', '120', '4', '692', 'true', '82%', '0.9', '45746');
INSERT INTO `flight` VALUES ('CZ6702', '东方航空', '空客320', '宁波', '深圳', '2021-08-13 15:00:00', '2021-08-13 17:00:00', '120', '30', '30', '346', '150', '3', '2163', '150', '4', '1175', '150', '4', '742', 'true', '96%', '0.8', '345345');
INSERT INTO `flight` VALUES ('CZ6922', '中国国航', '波音 789-9', '黎平', '广州', '2021-08-14 16:00:00', '2021-08-14 18:00:00', '120', '30', '7', '684', '229', '30', '2014', '229', '30', '1649', '229', '30', '638', 'true', '76%', '1.0', '634745');
INSERT INTO `flight` VALUES ('CZ6928', '中国国航', '空客A330-300', '天津', '呼和浩特', '2021-08-14 18:00:00', '2021-08-14 19:00:00', '60', '31', '1', '433', '255', '14', '2382', '255', '14', '1240', '255', '14', '962', 'true', '94%', '0.8', '758543');

-- ----------------------------
-- Table structure for managers
-- ----------------------------
DROP TABLE IF EXISTS `managers`;
CREATE TABLE `managers` (
  `id` char(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `company` varchar(20) NOT NULL,
  `name` varchar(20) NOT NULL,
  `mailbox` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `password` char(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of managers
-- ----------------------------
INSERT INTO `managers` VALUES ('132', '东方航空', '张三', '123@163.com', '123');
INSERT INTO `managers` VALUES ('admin123', '中国国航', '李四', '21233@qq.com', 'admin123');
INSERT INTO `managers` VALUES ('admin124', '南方航空', '赵五', '123', '123');

-- ----------------------------
-- Table structure for polit
-- ----------------------------
DROP TABLE IF EXISTS `polit`;
CREATE TABLE `polit` (
  `id` varchar(20) NOT NULL,
  `startplace` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `endplace` varchar(20) DEFAULT NULL,
  `starttime` datetime DEFAULT NULL,
  `endtime` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of polit
-- ----------------------------
INSERT INTO `polit` VALUES ('11', '福建', '北京', '2021-08-11 20:27:37', '2021-08-19 20:19:29');
INSERT INTO `polit` VALUES ('12', '天津', '厦门', '2021-08-07 20:27:41', '2021-09-17 20:19:57');
INSERT INTO `polit` VALUES ('14', '河南', '天津', '2021-09-10 20:27:58', '2021-09-25 20:19:52');
INSERT INTO `polit` VALUES ('13', '123', '123', '2000-01-01 00:00:00', '2003-01-01 00:00:00');
INSERT INTO `polit` VALUES ('13', '123', '123', '2000-01-01 00:00:00', '2003-01-01 00:00:00');
INSERT INTO `polit` VALUES ('12', '123', '123', '2000-01-01 00:00:00', '2003-01-01 00:00:00');
INSERT INTO `polit` VALUES ('12', '123', '123', '2000-01-01 00:00:00', '2003-01-01 00:00:00');
INSERT INTO `polit` VALUES ('1', 'wqw', '12', '1998-01-01 00:00:00', '2008-01-01 00:00:00');
INSERT INTO `polit` VALUES ('1', 'wqw', '12', '1998-01-01 00:00:00', '2008-01-01 00:00:00');
INSERT INTO `polit` VALUES ('14', 'wqw', '12', '1998-01-01 00:00:00', '2008-01-01 00:00:00');
INSERT INTO `polit` VALUES ('14', 'wqw', '12', '1998-01-01 00:00:00', '2008-01-01 00:00:00');
INSERT INTO `polit` VALUES ('11', '沈阳', '重庆', '2021-10-01 00:00:00', '2021-10-02 00:00:00');
INSERT INTO `polit` VALUES ('21', '沈阳', '重庆', '2021-10-01 00:00:00', '2021-10-02 00:00:00');
INSERT INTO `polit` VALUES ('11', '沈阳', '重庆', '2021-10-01 00:00:00', '2021-10-02 00:00:00');
INSERT INTO `polit` VALUES ('21', '沈阳', '重庆', '2021-10-01 00:00:00', '2021-10-02 00:00:00');
INSERT INTO `polit` VALUES ('22', '沈阳', '重庆', '2021-08-14 08:00:00', '2021-08-14 11:00:00');
INSERT INTO `polit` VALUES ('21', '沈阳', '重庆', '2021-08-14 08:00:00', '2021-08-14 11:00:00');
INSERT INTO `polit` VALUES ('19', '昆明', '杭州', '2021-10-01 00:00:00', '2021-10-02 00:00:00');
INSERT INTO `polit` VALUES ('09', '昆明', '杭州', '2021-10-01 00:00:00', '2021-10-02 00:00:00');
INSERT INTO `polit` VALUES ('01', '昆明', '思茅', '2021-10-11 00:00:00', '2021-10-12 00:00:00');
INSERT INTO `polit` VALUES ('02', '昆明', '思茅', '2021-10-11 00:00:00', '2021-10-12 00:00:00');

-- ----------------------------
-- Table structure for seattable
-- ----------------------------
DROP TABLE IF EXISTS `seattable`;
CREATE TABLE `seattable` (
  `seat` char(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `selled` enum('Yes','No') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT 'No',
  PRIMARY KEY (`seat`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of seattable
-- ----------------------------
INSERT INTO `seattable` VALUES ('01A', 'No');
INSERT INTO `seattable` VALUES ('01B', 'No');
INSERT INTO `seattable` VALUES ('01C', 'No');
INSERT INTO `seattable` VALUES ('01D', 'No');
INSERT INTO `seattable` VALUES ('01E', 'No');
INSERT INTO `seattable` VALUES ('01F', 'No');
INSERT INTO `seattable` VALUES ('02A', 'No');
INSERT INTO `seattable` VALUES ('02B', 'No');
INSERT INTO `seattable` VALUES ('02C', 'No');
INSERT INTO `seattable` VALUES ('02D', 'No');
INSERT INTO `seattable` VALUES ('02E', 'No');
INSERT INTO `seattable` VALUES ('02F', 'No');
INSERT INTO `seattable` VALUES ('03A', 'No');
INSERT INTO `seattable` VALUES ('03B', 'No');
INSERT INTO `seattable` VALUES ('03C', 'No');
INSERT INTO `seattable` VALUES ('03D', 'No');
INSERT INTO `seattable` VALUES ('03E', 'No');
INSERT INTO `seattable` VALUES ('03F', 'No');
INSERT INTO `seattable` VALUES ('04A', 'No');
INSERT INTO `seattable` VALUES ('04B', 'No');
INSERT INTO `seattable` VALUES ('04C', 'No');
INSERT INTO `seattable` VALUES ('04D', 'No');
INSERT INTO `seattable` VALUES ('04E', 'No');
INSERT INTO `seattable` VALUES ('04F', 'No');
INSERT INTO `seattable` VALUES ('05A', 'No');
INSERT INTO `seattable` VALUES ('05B', 'No');
INSERT INTO `seattable` VALUES ('05C', 'No');
INSERT INTO `seattable` VALUES ('05D', 'No');
INSERT INTO `seattable` VALUES ('05E', 'No');
INSERT INTO `seattable` VALUES ('05F', 'No');
INSERT INTO `seattable` VALUES ('06A', 'No');
INSERT INTO `seattable` VALUES ('06B', 'No');
INSERT INTO `seattable` VALUES ('06C', 'No');
INSERT INTO `seattable` VALUES ('06D', 'No');
INSERT INTO `seattable` VALUES ('06E', 'No');
INSERT INTO `seattable` VALUES ('06F', 'No');
INSERT INTO `seattable` VALUES ('07A', 'No');
INSERT INTO `seattable` VALUES ('07B', 'Yes');
INSERT INTO `seattable` VALUES ('07C', 'No');
INSERT INTO `seattable` VALUES ('07D', 'No');
INSERT INTO `seattable` VALUES ('07E', 'No');
INSERT INTO `seattable` VALUES ('07F', 'No');
INSERT INTO `seattable` VALUES ('08A', 'No');
INSERT INTO `seattable` VALUES ('08B', 'No');
INSERT INTO `seattable` VALUES ('08C', 'No');
INSERT INTO `seattable` VALUES ('08D', 'No');
INSERT INTO `seattable` VALUES ('08E', 'No');
INSERT INTO `seattable` VALUES ('08F', 'No');
INSERT INTO `seattable` VALUES ('09A', 'No');
INSERT INTO `seattable` VALUES ('09B', 'No');
INSERT INTO `seattable` VALUES ('09C', 'No');
INSERT INTO `seattable` VALUES ('09D', 'No');
INSERT INTO `seattable` VALUES ('09E', 'No');
INSERT INTO `seattable` VALUES ('09F', 'No');
INSERT INTO `seattable` VALUES ('10A', 'No');
INSERT INTO `seattable` VALUES ('10B', 'No');
INSERT INTO `seattable` VALUES ('10C', 'No');
INSERT INTO `seattable` VALUES ('10D', 'No');
INSERT INTO `seattable` VALUES ('10E', 'No');
INSERT INTO `seattable` VALUES ('10F', 'No');
INSERT INTO `seattable` VALUES ('11A', 'No');
INSERT INTO `seattable` VALUES ('11B', 'No');
INSERT INTO `seattable` VALUES ('11C', 'No');
INSERT INTO `seattable` VALUES ('11D', 'No');
INSERT INTO `seattable` VALUES ('11E', 'No');
INSERT INTO `seattable` VALUES ('11F', 'No');
INSERT INTO `seattable` VALUES ('12A', 'No');
INSERT INTO `seattable` VALUES ('12B', 'No');
INSERT INTO `seattable` VALUES ('12C', 'No');
INSERT INTO `seattable` VALUES ('12D', 'No');
INSERT INTO `seattable` VALUES ('12E', 'No');
INSERT INTO `seattable` VALUES ('12F', 'No');
INSERT INTO `seattable` VALUES ('13A', 'No');
INSERT INTO `seattable` VALUES ('13B', 'No');
INSERT INTO `seattable` VALUES ('13C', 'No');
INSERT INTO `seattable` VALUES ('13D', 'No');
INSERT INTO `seattable` VALUES ('13E', 'No');
INSERT INTO `seattable` VALUES ('13F', 'No');
INSERT INTO `seattable` VALUES ('14A', 'No');
INSERT INTO `seattable` VALUES ('14B', 'No');
INSERT INTO `seattable` VALUES ('14C', 'No');
INSERT INTO `seattable` VALUES ('14D', 'No');
INSERT INTO `seattable` VALUES ('14E', 'No');
INSERT INTO `seattable` VALUES ('14F', 'No');
INSERT INTO `seattable` VALUES ('15A', 'No');
INSERT INTO `seattable` VALUES ('15B', 'No');
INSERT INTO `seattable` VALUES ('15C', 'No');
INSERT INTO `seattable` VALUES ('15D', 'No');
INSERT INTO `seattable` VALUES ('15E', 'No');
INSERT INTO `seattable` VALUES ('15F', 'No');
INSERT INTO `seattable` VALUES ('16A', 'No');
INSERT INTO `seattable` VALUES ('16B', 'No');
INSERT INTO `seattable` VALUES ('16C', 'No');
INSERT INTO `seattable` VALUES ('16D', 'Yes');
INSERT INTO `seattable` VALUES ('16E', 'No');
INSERT INTO `seattable` VALUES ('16F', 'No');

-- ----------------------------
-- Table structure for ticketselled
-- ----------------------------
DROP TABLE IF EXISTS `ticketselled`;
CREATE TABLE `ticketselled` (
  `num` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `company` varchar(20) DEFAULT NULL,
  `buyer` varchar(20) DEFAULT NULL,
  `seat` varchar(20) DEFAULT NULL,
  `buydate` date DEFAULT NULL,
  `pay` enum('Yes','No') DEFAULT 'No',
  `seattype` enum('头等舱','商务舱','经济舱') DEFAULT NULL,
  `seatprice` int DEFAULT NULL,
  `buyername` varchar(20) DEFAULT NULL,
  `startplace` varchar(20) DEFAULT NULL,
  `endplace` varchar(20) DEFAULT NULL,
  `starttime` datetime DEFAULT NULL,
  `endtime` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of ticketselled
-- ----------------------------
INSERT INTO `ticketselled` VALUES ('CZ3148', '中国国航', 'admin123', '04A', '2021-09-09', 'Yes', '商务舱', '1475', '张三', '北京', '北海', '2021-09-17 20:00:00', '2021-08-14 01:00:00');
INSERT INTO `ticketselled` VALUES ('CZ3253', '南方航空', 'admin123', '07B', '2021-09-09', 'Yes', '经济舱', '849', '刻画', '桂林', '南京', '2021-08-13 08:00:00', '2021-08-13 09:00:00');
INSERT INTO `ticketselled` VALUES ('CZ3253', '南方航空', 'admin123', '05C', '2021-09-09', 'Yes', '商务舱', '1807', '刻画', '桂林', '南京', '2021-08-13 08:00:00', '2021-08-13 09:00:00');
INSERT INTO `ticketselled` VALUES ('CZ3663', '中国国航', 'admin123', '11B', '2021-09-06', 'No', '经济舱', '842', '赵四', '广州', '北海', '2021-08-13 11:00:00', '2021-08-14 00:00:00');
INSERT INTO `ticketselled` VALUES ('CZ3764', '中国国航', 'admin123', '06B', '2021-09-05', 'No', '商务舱', '1502', '河南', '温州', '广州', '2021-08-14 14:00:00', '2021-08-14 15:00:00');
INSERT INTO `ticketselled` VALUES ('CZ3148', '中国国航', 'admin123', '01A', '2021-09-10', 'Yes', '头等舱', '2568', '啊啊', '北京', '北海', '2021-09-17 20:00:00', '2021-08-14 01:00:00');
INSERT INTO `ticketselled` VALUES ('CZ3128', '东方航空', 'admin123', '11D', '2021-09-10', 'Yes', '经济舱', '841', '娜娜', '北京', '长沙', '2021-08-13 20:00:00', '2021-08-13 23:00:00');
INSERT INTO `ticketselled` VALUES ('CZ3128', '东方航空', 'admin123', '12F', '2021-09-10', 'Yes', '经济舱', '841', '大大', '北京', '长沙', '2021-08-13 20:00:00', '2021-08-13 23:00:00');
INSERT INTO `ticketselled` VALUES ('CZ3128', '东方航空', 'admin123', '13F', '2021-09-10', 'Yes', '经济舱', '841', '大乐', '北京', '长沙', '2021-08-13 20:00:00', '2021-08-13 23:00:00');
INSERT INTO `ticketselled` VALUES ('AB1456', '中国国航', 'admin123', '14F', '2021-09-01', 'Yes', '商务舱', '1200', '赵四', '昆明', '思茅', '2021-10-11 00:00:00', '2021-10-12 00:00:00');
INSERT INTO `ticketselled` VALUES ('CZ3253', '南方航空', 'admin123', '16D', '2021-09-11', 'Yes', '经济舱', '849', '大', '桂林', '南京', '2021-08-30 08:00:00', '2021-08-13 09:00:00');

-- ----------------------------
-- Table structure for users
-- ----------------------------
DROP TABLE IF EXISTS `users`;
CREATE TABLE `users` (
  `id` char(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `name` varchar(20) NOT NULL,
  `sex` enum('女','男') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `phone` char(11) NOT NULL,
  `password` char(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `mailbox` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of users
-- ----------------------------
INSERT INTO `users` VALUES ('124', '李四', '女', '18750220537', '123', '18750220537@163.com');
INSERT INTO `users` VALUES ('125', '赵五', '男', '18273849238', '123', '1837492387@bupt.edu.');
INSERT INTO `users` VALUES ('admin123', '张三', '男', '18748959374', 'admin123', 'admin123@qq.com');

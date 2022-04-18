/*
 Navicat MySQL Data Transfer

 Source Server         : sa
 Source Server Type    : MySQL
 Source Server Version : 100424
 Source Host           : localhost:3306
 Source Schema         : nrp

 Target Server Type    : MySQL
 Target Server Version : 100424
 File Encoding         : 65001

 Date: 18/04/2022 15:55:44
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for achievements
-- ----------------------------
DROP TABLE IF EXISTS `achievements`;
CREATE TABLE `achievements`  (
  `uid` int NULL DEFAULT NULL,
  `achievement` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  UNIQUE INDEX `uid`(`uid` ASC, `achievement` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of achievements
-- ----------------------------
INSERT INTO `achievements` VALUES (36, 'High roller');
INSERT INTO `achievements` VALUES (36, 'I\'m rich!');

-- ----------------------------
-- Table structure for actordb
-- ----------------------------
DROP TABLE IF EXISTS `actordb`;
CREATE TABLE `actordb`  (
  `ID` int NOT NULL,
  `ActorName` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `ActorVirtual` int NOT NULL,
  `ActorX` float NOT NULL,
  `ActorA` float NOT NULL,
  `ActorY` float NOT NULL,
  `ActorZ` float NOT NULL,
  `Skin` int NOT NULL,
  `AActive` int NOT NULL,
  `Text` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = COMPACT;

-- ----------------------------
-- Records of actordb
-- ----------------------------

-- ----------------------------
-- Table structure for admins
-- ----------------------------
DROP TABLE IF EXISTS `admins`;
CREATE TABLE `admins`  (
  `uid` int NOT NULL,
  `username` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `aName` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `aLevel` int NOT NULL,
  `totalReports` int NOT NULL,
  `monthlyReports` int NOT NULL,
  `weeklyReports` int NOT NULL,
  `monthlyReset` int NOT NULL,
  `weeklyReset` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of admins
-- ----------------------------

-- ----------------------------
-- Table structure for arrestpoints
-- ----------------------------
DROP TABLE IF EXISTS `arrestpoints`;
CREATE TABLE `arrestpoints`  (
  `id` int NOT NULL,
  `PosX` float(10, 5) NOT NULL DEFAULT 0.00000,
  `PosY` float(10, 5) NOT NULL DEFAULT 0.00000,
  `PosZ` float(10, 5) NOT NULL DEFAULT 0.00000,
  `VW` int NOT NULL DEFAULT 0,
  `Int` int NOT NULL DEFAULT 0,
  `Type` int NOT NULL DEFAULT 0,
  `jailVW` int NOT NULL DEFAULT 0,
  `jailInt` int NOT NULL DEFAULT 0,
  `jailpos1x` float(10, 5) NOT NULL DEFAULT 0.00000,
  `jailpos1y` float(10, 5) NOT NULL DEFAULT 0.00000,
  `jailpos1z` float(10, 5) NOT NULL DEFAULT 0.00000,
  `jailpos2x` float(10, 5) NOT NULL DEFAULT 0.00000,
  `jailpos2y` float(10, 5) NOT NULL DEFAULT 0.00000,
  `jailpos2z` float(10, 5) NOT NULL DEFAULT 0.00000
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of arrestpoints
-- ----------------------------

-- ----------------------------
-- Table structure for atms
-- ----------------------------
DROP TABLE IF EXISTS `atms`;
CREATE TABLE `atms`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `pos_x` float NULL DEFAULT NULL,
  `pos_y` float NULL DEFAULT NULL,
  `pos_z` float NULL DEFAULT NULL,
  `pos_r` float NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 15 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of atms
-- ----------------------------

-- ----------------------------
-- Table structure for auctions
-- ----------------------------
DROP TABLE IF EXISTS `auctions`;
CREATE TABLE `auctions`  (
  `id` int NOT NULL,
  `BiddingFor` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '(none)',
  `InProgress` int NOT NULL DEFAULT 0,
  `Bid` int NOT NULL DEFAULT 0,
  `Bidder` int NOT NULL DEFAULT 0,
  `Expires` int NOT NULL DEFAULT 0,
  `Wining` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '(none)',
  `Increment` int NOT NULL DEFAULT 0
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = COMPACT;

-- ----------------------------
-- Records of auctions
-- ----------------------------

-- ----------------------------
-- Table structure for backpack
-- ----------------------------
DROP TABLE IF EXISTS `backpack`;
CREATE TABLE `backpack`  (
  `pid` int NOT NULL,
  `type` int NOT NULL,
  `store1` int NULL DEFAULT NULL,
  `store2` int NULL DEFAULT NULL,
  `food` int NOT NULL DEFAULT 0,
  `food2` int NOT NULL DEFAULT 0,
  `mats` int NOT NULL DEFAULT 0,
  `pot` int NULL DEFAULT 0,
  `crack` int NULL DEFAULT 0,
  `heroine` int NULL DEFAULT 0,
  `weap1` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `weap2` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `weap3` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `weap4` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `weap5` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `Cash` int NOT NULL DEFAULT 0
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = COMPACT;

-- ----------------------------
-- Records of backpack
-- ----------------------------

-- ----------------------------
-- Table structure for bans
-- ----------------------------
DROP TABLE IF EXISTS `bans`;
CREATE TABLE `bans`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `username` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `ip` varchar(16) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `bannedby` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `date` datetime NULL DEFAULT NULL,
  `reason` varchar(128) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `permanent` tinyint(1) NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 32 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of bans
-- ----------------------------

-- ----------------------------
-- Table structure for businesses
-- ----------------------------
DROP TABLE IF EXISTS `businesses`;
CREATE TABLE `businesses`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `ownerid` int NULL DEFAULT 0,
  `owner` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'Nobody',
  `type` tinyint NULL DEFAULT 0,
  `price` int NULL DEFAULT 0,
  `entryfee` int NULL DEFAULT 0,
  `locked` tinyint(1) NULL DEFAULT 0,
  `timestamp` int NULL DEFAULT 0,
  `pos_x` float NULL DEFAULT 0,
  `pos_y` float NULL DEFAULT 0,
  `pos_z` float NULL DEFAULT 0,
  `pos_a` float NULL DEFAULT 0,
  `int_x` float NULL DEFAULT 0,
  `int_y` float NULL DEFAULT 0,
  `int_z` float NULL DEFAULT 0,
  `int_a` float NULL DEFAULT 0,
  `interior` tinyint NULL DEFAULT 0,
  `world` int NULL DEFAULT 0,
  `outsideint` tinyint NULL DEFAULT 0,
  `outsidevw` int NULL DEFAULT 0,
  `cash` int NULL DEFAULT 0,
  `products` int NULL DEFAULT 500,
  `name` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'Business Name',
  `message` varchar(128) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'Welcome use /buy to buy from this business',
  `color` int NULL DEFAULT -256,
  `freeze` tinyint(1) NULL DEFAULT 1,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 422 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of businesses
-- ----------------------------
INSERT INTO `businesses` VALUES (418, 36, 'Kiet_Le', 4, 500000, 0, 0, 1650266319, 1367.51, 248.384, 19.567, 56.637, 363.328, -74.65, 1001.51, 315, 10, 1108, 0, 0, 0, 500, 'Business Name', 'Welcome use /buy to buy from this business', -256, 1);
INSERT INTO `businesses` VALUES (419, 0, 'Nobody', 0, 600000, 0, 0, 0, 1356.99, 308.094, 19.747, 162.041, -27.438, -57.611, 1003.55, 0, 6, 3000419, 0, 0, 700, 498, 'Business Name', 'Welcome use /buy to buy from this business', -256, 1);
INSERT INTO `businesses` VALUES (420, 0, 'Nobody', 4, 500000, 0, 0, 0, 203.443, -202.145, 1.578, -178.799, 363.328, -74.65, 1001.51, 315, 10, 3000420, 0, 0, 0, 500, 'Business Name', 'Welcome use /buy to buy from this business', -256, 1);
INSERT INTO `businesses` VALUES (421, 0, 'Nobody', 2, 750000, 0, 0, 0, 171.842, -200.902, 1.57, -139.277, 204.386, -168.459, 1000.52, 0, 14, 3000421, 0, 0, 1875, 497, 'Business Name', 'Welcome use /buy to buy from this business', -256, 1);

-- ----------------------------
-- Table structure for changes
-- ----------------------------
DROP TABLE IF EXISTS `changes`;
CREATE TABLE `changes`  (
  `slot` tinyint NULL DEFAULT NULL,
  `text` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  UNIQUE INDEX `slot`(`slot` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of changes
-- ----------------------------

-- ----------------------------
-- Table structure for charges
-- ----------------------------
DROP TABLE IF EXISTS `charges`;
CREATE TABLE `charges`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `uid` int NULL DEFAULT NULL,
  `chargedby` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `date` datetime NULL DEFAULT NULL,
  `reason` varchar(128) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 108 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of charges
-- ----------------------------

-- ----------------------------
-- Table structure for clothing
-- ----------------------------
DROP TABLE IF EXISTS `clothing`;
CREATE TABLE `clothing`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `uid` int NULL DEFAULT NULL,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `modelid` smallint NULL DEFAULT NULL,
  `boneid` tinyint NULL DEFAULT NULL,
  `attached` tinyint(1) NULL DEFAULT NULL,
  `pos_x` float NULL DEFAULT NULL,
  `pos_y` float NULL DEFAULT NULL,
  `pos_z` float NULL DEFAULT NULL,
  `rot_x` float NULL DEFAULT NULL,
  `rot_y` float NULL DEFAULT NULL,
  `rot_z` float NULL DEFAULT NULL,
  `scale_x` float NULL DEFAULT NULL,
  `scale_y` float NULL DEFAULT NULL,
  `scale_z` float NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 7334 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of clothing
-- ----------------------------
INSERT INTO `clothing` VALUES (7332, 36, 'Gag glasses', 19013, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1);
INSERT INTO `clothing` VALUES (7333, 36, 'White hockey mask', 19036, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1);

-- ----------------------------
-- Table structure for crates
-- ----------------------------
DROP TABLE IF EXISTS `crates`;
CREATE TABLE `crates`  (
  `id` int NOT NULL,
  `Active` int NOT NULL DEFAULT 0,
  `CrateX` float NOT NULL DEFAULT 0,
  `CrateY` float NOT NULL DEFAULT 0,
  `CrateZ` float NOT NULL DEFAULT 0,
  `GunQuantity` int NOT NULL DEFAULT 50,
  `InVehicle` int NOT NULL DEFAULT 0,
  `Int` int NOT NULL DEFAULT 0,
  `VW` int NOT NULL DEFAULT 0,
  `PlacedBy` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'Unknown'
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of crates
-- ----------------------------

-- ----------------------------
-- Table structure for crews
-- ----------------------------
DROP TABLE IF EXISTS `crews`;
CREATE TABLE `crews`  (
  `id` tinyint NULL DEFAULT NULL,
  `crewid` tinyint NULL DEFAULT NULL,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  UNIQUE INDEX `id`(`id` ASC, `crewid` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of crews
-- ----------------------------

-- ----------------------------
-- Table structure for divisions
-- ----------------------------
DROP TABLE IF EXISTS `divisions`;
CREATE TABLE `divisions`  (
  `id` tinyint NULL DEFAULT NULL,
  `divisionid` tinyint NULL DEFAULT NULL,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  UNIQUE INDEX `id`(`id` ASC, `divisionid` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of divisions
-- ----------------------------
INSERT INTO `divisions` VALUES (0, 0, 'IA');
INSERT INTO `divisions` VALUES (0, 1, 'TnR');
INSERT INTO `divisions` VALUES (0, 2, 'HSIU');
INSERT INTO `divisions` VALUES (0, 3, 'DET');

-- ----------------------------
-- Table structure for entrances
-- ----------------------------
DROP TABLE IF EXISTS `entrances`;
CREATE TABLE `entrances`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `ownerid` int NULL DEFAULT 0,
  `owner` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `name` varchar(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `iconid` smallint NULL DEFAULT 1239,
  `locked` tinyint(1) NULL DEFAULT 0,
  `radius` float NULL DEFAULT 3,
  `pos_x` float NULL DEFAULT 0,
  `pos_y` float NULL DEFAULT 0,
  `pos_z` float NULL DEFAULT 0,
  `pos_a` float NULL DEFAULT 0,
  `int_x` float NULL DEFAULT 0,
  `int_y` float NULL DEFAULT 0,
  `int_z` float NULL DEFAULT 0,
  `int_a` float NULL DEFAULT 0,
  `interior` tinyint NULL DEFAULT 0,
  `world` int NULL DEFAULT 0,
  `outsideint` tinyint NULL DEFAULT 0,
  `outsidevw` int NULL DEFAULT 0,
  `adminlevel` tinyint NULL DEFAULT 0,
  `factiontype` tinyint NULL DEFAULT 0,
  `vip` tinyint NULL DEFAULT 0,
  `vehicles` tinyint(1) NULL DEFAULT 0,
  `freeze` tinyint(1) NULL DEFAULT 1,
  `password` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'None',
  `label` tinyint(1) NULL DEFAULT 1,
  `mapicon` tinyint NOT NULL DEFAULT 0,
  `gang` tinyint NULL DEFAULT -1,
  `type` tinyint NULL DEFAULT 0,
  `color` int NULL DEFAULT -256,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 320 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of entrances
-- ----------------------------

-- ----------------------------
-- Table structure for factionlockers
-- ----------------------------
DROP TABLE IF EXISTS `factionlockers`;
CREATE TABLE `factionlockers`  (
  `pos_x` float NULL DEFAULT 0,
  `pos_y` float NULL DEFAULT 0,
  `factionid` tinyint NULL DEFAULT NULL,
  `interior` tinyint NULL DEFAULT 0,
  `pos_z` float NULL DEFAULT 0,
  `world` int NULL DEFAULT 0,
  `id` int NOT NULL AUTO_INCREMENT,
  `iconid` smallint NULL DEFAULT 1239,
  `label` tinyint(1) NULL DEFAULT 1,
  `weapon_kevlar` tinyint(1) NULL DEFAULT 1,
  `weapon_medkit` tinyint(1) NULL DEFAULT 1,
  `weapon_nitestick` varchar(1) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT '0',
  `weapon_mace` tinyint(1) NULL DEFAULT 0,
  `weapon_deagle` tinyint(1) NULL DEFAULT 1,
  `weapon_shotgun` tinyint(1) NULL DEFAULT 1,
  `weapon_mp5` tinyint(1) NULL DEFAULT 1,
  `weapon_m4` tinyint(1) NULL DEFAULT 1,
  `weapon_sniper` tinyint(1) NULL DEFAULT 1,
  `weapon_spas12` tinyint(1) NULL DEFAULT 1,
  `weapon_camera` tinyint NULL DEFAULT 0,
  `weapon_fire_extinguisher` tinyint NULL DEFAULT 0,
  `weapon_painkillers` tinyint NULL DEFAULT 0,
  `price_kevlar` smallint NULL DEFAULT 100,
  `price_medkit` smallint NULL DEFAULT 50,
  `price_nitestick` smallint NULL DEFAULT 0,
  `price_mace` smallint NULL DEFAULT 0,
  `price_deagle` smallint NULL DEFAULT 1000,
  `price_shotgun` smallint NULL DEFAULT 1000,
  `price_mp5` smallint NULL DEFAULT 2500,
  `price_m4` smallint NULL DEFAULT 3500,
  `price_sniper` smallint NULL DEFAULT 8500,
  `price_spas12` smallint NULL DEFAULT 7500,
  `price_camera` smallint NULL DEFAULT 100,
  `price_fire_extinguisher` smallint NULL DEFAULT 100,
  `price_painkillers` smallint NULL DEFAULT 100,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 17 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of factionlockers
-- ----------------------------

-- ----------------------------
-- Table structure for factionpay
-- ----------------------------
DROP TABLE IF EXISTS `factionpay`;
CREATE TABLE `factionpay`  (
  `id` tinyint NULL DEFAULT NULL,
  `rank` tinyint NULL DEFAULT NULL,
  `amount` int NULL DEFAULT NULL,
  UNIQUE INDEX `id`(`id` ASC, `rank` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of factionpay
-- ----------------------------
INSERT INTO `factionpay` VALUES (0, 0, 100);
INSERT INTO `factionpay` VALUES (0, 1, 250);
INSERT INTO `factionpay` VALUES (0, 3, 550);
INSERT INTO `factionpay` VALUES (0, 2, 450);
INSERT INTO `factionpay` VALUES (0, 4, 600);
INSERT INTO `factionpay` VALUES (0, 5, 650);
INSERT INTO `factionpay` VALUES (0, 6, 700);
INSERT INTO `factionpay` VALUES (0, 8, 950);
INSERT INTO `factionpay` VALUES (0, 9, 1500);

-- ----------------------------
-- Table structure for factionranks
-- ----------------------------
DROP TABLE IF EXISTS `factionranks`;
CREATE TABLE `factionranks`  (
  `id` tinyint NULL DEFAULT NULL,
  `rank` tinyint NULL DEFAULT NULL,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  UNIQUE INDEX `id`(`id` ASC, `rank` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of factionranks
-- ----------------------------
INSERT INTO `factionranks` VALUES (0, 1, 'Officer');
INSERT INTO `factionranks` VALUES (0, 0, 'Cadet');
INSERT INTO `factionranks` VALUES (0, 2, 'Senior Officer');
INSERT INTO `factionranks` VALUES (0, 3, 'Corporal');
INSERT INTO `factionranks` VALUES (0, 4, 'Sergeant');
INSERT INTO `factionranks` VALUES (0, 5, 'Staff Sergeant');
INSERT INTO `factionranks` VALUES (0, 6, 'Lieutenant');
INSERT INTO `factionranks` VALUES (0, 7, 'Captain');
INSERT INTO `factionranks` VALUES (0, 8, 'Deputy Chief');
INSERT INTO `factionranks` VALUES (0, 9, 'Chief Of Police');
INSERT INTO `factionranks` VALUES (1, 0, 'Trainee');
INSERT INTO `factionranks` VALUES (1, 1, 'Intermediate');
INSERT INTO `factionranks` VALUES (1, 2, 'Paramedic');
INSERT INTO `factionranks` VALUES (1, 3, 'Fire Protection');
INSERT INTO `factionranks` VALUES (1, 4, 'Lieutenant');
INSERT INTO `factionranks` VALUES (1, 5, 'Captain');
INSERT INTO `factionranks` VALUES (1, 6, 'Battalion Chief');
INSERT INTO `factionranks` VALUES (1, 7, 'Deputy Chief');
INSERT INTO `factionranks` VALUES (1, 8, 'Deputy Hospital');
INSERT INTO `factionranks` VALUES (1, 9, 'Chief Of Hospital');

-- ----------------------------
-- Table structure for factions
-- ----------------------------
DROP TABLE IF EXISTS `factions`;
CREATE TABLE `factions`  (
  `id` tinyint NULL DEFAULT NULL,
  `name` varchar(48) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `leader` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'No-one',
  `type` tinyint NULL DEFAULT 0,
  `color` int NULL DEFAULT -1,
  `rankcount` tinyint NULL DEFAULT 6,
  `lockerx` float NULL DEFAULT 0,
  `lockery` float NULL DEFAULT 0,
  `lockerz` float NULL DEFAULT 0,
  `lockerinterior` tinyint NULL DEFAULT 0,
  `lockerworld` int NULL DEFAULT 0,
  `turftokens` int NULL DEFAULT NULL,
  `shortname` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `motd` varchar(128) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `budget` int NULL DEFAULT 0,
  UNIQUE INDEX `id`(`id` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of factions
-- ----------------------------
INSERT INTO `factions` VALUES (0, 'Los Santos Police Department', 'No-one', 1, -1, 10, 0, 0, 0, 0, 0, NULL, 'LSPD', NULL, 0);
INSERT INTO `factions` VALUES (1, 'Los Santos Fire/Medic Department', 'No-one', 2, -1, 10, 0, 0, 0, 0, 0, NULL, 'LSFMD', NULL, 0);
INSERT INTO `factions` VALUES (2, 'SASD', 'No-one', 1, -1, 6, 0, 0, 0, 0, 0, NULL, NULL, NULL, 0);

-- ----------------------------
-- Table structure for factionskins
-- ----------------------------
DROP TABLE IF EXISTS `factionskins`;
CREATE TABLE `factionskins`  (
  `id` tinyint NULL DEFAULT NULL,
  `slot` tinyint NULL DEFAULT NULL,
  `skinid` smallint NULL DEFAULT NULL,
  UNIQUE INDEX `id`(`id` ASC, `slot` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of factionskins
-- ----------------------------
INSERT INTO `factionskins` VALUES (1, 0, 274);
INSERT INTO `factionskins` VALUES (1, 1, 275);
INSERT INTO `factionskins` VALUES (1, 2, 276);
INSERT INTO `factionskins` VALUES (1, 3, 277);

-- ----------------------------
-- Table structure for families
-- ----------------------------
DROP TABLE IF EXISTS `families`;
CREATE TABLE `families`  (
  `ID` int NOT NULL,
  `Taken` int NOT NULL,
  `Name` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `MOTD` varchar(128) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `Leader` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `Bank` int NOT NULL,
  `Cash` int NOT NULL,
  `USafe` int NOT NULL,
  `SafeX` float NOT NULL,
  `SafeY` float NOT NULL,
  `SafeZ` float NOT NULL,
  `Pot` int NOT NULL,
  `Crack` int NOT NULL,
  `Mats` int NOT NULL,
  `Rank1` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `Rank2` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `Rank3` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `Rank4` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `Rank5` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `Rank6` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `Members` int NOT NULL,
  `MaxSkins` int NOT NULL,
  `Skins0` int NOT NULL,
  `Skins1` int NOT NULL,
  `Skins2` int NOT NULL,
  `Skins3` int NOT NULL,
  `Skins4` int NOT NULL,
  `Skins5` int NOT NULL,
  `Skins6` int NOT NULL,
  `Skins7` int NOT NULL,
  `Color` int NOT NULL,
  `TurfTokens` int NOT NULL,
  `Guns0` int NOT NULL,
  `Guns1` int NOT NULL,
  `Guns2` int NOT NULL,
  `Guns3` int NOT NULL,
  `Guns4` int NOT NULL,
  `Guns5` int NOT NULL,
  `Guns6` int NOT NULL,
  `Guns7` int NOT NULL,
  `Guns8` int NOT NULL,
  `Guns9` int NOT NULL,
  `Heroin` int NOT NULL,
  `GunAmmo0` int NOT NULL,
  `GunAmmo1` int NOT NULL,
  `GunAmmo2` int NOT NULL,
  `GunAmmo3` int NOT NULL,
  `GunAmmo4` int NOT NULL,
  `GunAmmo5` int NOT NULL,
  `GunAmmo6` int NOT NULL,
  `GunAmmo7` int NOT NULL,
  `GunAmmo8` int NOT NULL,
  `GunAmmo9` int NOT NULL,
  `Meth` int NOT NULL,
  `Seeds` int NOT NULL,
  `Opium` int NOT NULL,
  `Acid` int NOT NULL,
  `CrackStuff` int NOT NULL,
  `Rank0` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of families
-- ----------------------------

-- ----------------------------
-- Table structure for flags
-- ----------------------------
DROP TABLE IF EXISTS `flags`;
CREATE TABLE `flags`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `uid` int NULL DEFAULT NULL,
  `flaggedby` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(128) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 35 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of flags
-- ----------------------------

-- ----------------------------
-- Table structure for furniture
-- ----------------------------
DROP TABLE IF EXISTS `furniture`;
CREATE TABLE `furniture`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `houseid` int NULL DEFAULT NULL,
  `modelid` smallint NULL DEFAULT NULL,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `price` int NULL DEFAULT NULL,
  `pos_x` float NULL DEFAULT NULL,
  `pos_y` float NULL DEFAULT NULL,
  `pos_z` float NULL DEFAULT NULL,
  `rot_x` float NULL DEFAULT NULL,
  `rot_y` float NULL DEFAULT NULL,
  `rot_z` float NULL DEFAULT NULL,
  `interior` tinyint NULL DEFAULT NULL,
  `world` int NULL DEFAULT NULL,
  `door_opened` tinyint(1) NULL DEFAULT 0,
  `door_locked` tinyint(1) NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 243 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of furniture
-- ----------------------------

-- ----------------------------
-- Table structure for gangranks
-- ----------------------------
DROP TABLE IF EXISTS `gangranks`;
CREATE TABLE `gangranks`  (
  `id` tinyint NULL DEFAULT NULL,
  `rank` tinyint NULL DEFAULT NULL,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  UNIQUE INDEX `id`(`id` ASC, `rank` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of gangranks
-- ----------------------------

-- ----------------------------
-- Table structure for gangs
-- ----------------------------
DROP TABLE IF EXISTS `gangs`;
CREATE TABLE `gangs`  (
  `id` tinyint NULL DEFAULT NULL,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'None',
  `motd` varchar(128) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'None',
  `leader` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'No-one',
  `color` int NULL DEFAULT -256,
  `strikes` tinyint(1) NULL DEFAULT 0,
  `level` tinyint NULL DEFAULT 1,
  `points` int NULL DEFAULT 0,
  `turftokens` int NULL DEFAULT 0,
  `stash_x` float NULL DEFAULT 0,
  `stash_y` float NULL DEFAULT 0,
  `stash_z` float NULL DEFAULT 0,
  `stashinterior` tinyint NULL DEFAULT 0,
  `stashworld` int NULL DEFAULT 0,
  `cash` int NULL DEFAULT 0,
  `materials` int NULL DEFAULT 0,
  `weed` int NULL DEFAULT 0,
  `cocaine` int NULL DEFAULT 0,
  `meth` int NULL DEFAULT 0,
  `painkillers` int NULL DEFAULT 0,
  `pistolammo` int NULL DEFAULT 0,
  `shotgunammo` int NULL DEFAULT 0,
  `smgammo` int NULL DEFAULT 0,
  `arammo` int NULL DEFAULT 0,
  `rifleammo` int NULL DEFAULT 0,
  `hpammo` int NULL DEFAULT 0,
  `poisonammo` int NULL DEFAULT 0,
  `fmjammo` int NULL DEFAULT 0,
  `weapon_9mm` int NULL DEFAULT 0,
  `weapon_sdpistol` int NULL DEFAULT 0,
  `weapon_deagle` int NULL DEFAULT 0,
  `weapon_shotgun` int NULL DEFAULT 0,
  `weapon_spas12` int NULL DEFAULT 0,
  `weapon_sawnoff` int NULL DEFAULT 0,
  `weapon_tec9` int NULL DEFAULT 0,
  `weapon_uzi` int NULL DEFAULT 0,
  `weapon_mp5` int NULL DEFAULT 0,
  `weapon_ak47` int NULL DEFAULT 0,
  `weapon_m4` int NULL DEFAULT 0,
  `weapon_rifle` int NULL DEFAULT 0,
  `weapon_sniper` int NULL DEFAULT 0,
  `weapon_molotov` int NULL DEFAULT 0,
  `armsdealer` tinyint(1) NULL DEFAULT 0,
  `drugdealer` tinyint(1) NULL DEFAULT 0,
  `arms_x` float NULL DEFAULT 0,
  `arms_y` float NULL DEFAULT 0,
  `arms_z` float NULL DEFAULT 0,
  `arms_a` float NULL DEFAULT 0,
  `drug_x` float NULL DEFAULT 0,
  `drug_y` float NULL DEFAULT 0,
  `drug_z` float NULL DEFAULT 0,
  `drug_a` float NULL DEFAULT 0,
  `armsworld` int NULL DEFAULT 0,
  `drugworld` int NULL DEFAULT 0,
  `drugweed` int NULL DEFAULT 0,
  `drugcocaine` int NULL DEFAULT 0,
  `drugmeth` int NULL DEFAULT 0,
  `armsmaterials` int NULL DEFAULT 0,
  `armsprice_1` int NULL DEFAULT 0,
  `armsprice_2` int NULL DEFAULT 0,
  `armsprice_3` int NULL DEFAULT 0,
  `armsprice_4` int NULL DEFAULT 0,
  `armsprice_5` int NULL DEFAULT 0,
  `armsprice_6` int NULL DEFAULT 0,
  `armsprice_7` int NULL DEFAULT 0,
  `armsprice_8` int NULL DEFAULT 0,
  `armsprice_9` int NOT NULL DEFAULT 0,
  `armsprice_10` int NOT NULL DEFAULT 0,
  `armsprice_11` int NOT NULL DEFAULT 0,
  `armsprice_12` tinyint NOT NULL DEFAULT 0,
  `weed_price` int NULL DEFAULT 0,
  `cocaine_price` int NULL DEFAULT 0,
  `meth_price` int NULL DEFAULT 0,
  `matlevel` tinyint NOT NULL DEFAULT 0,
  `gunlevel` tinyint NOT NULL DEFAULT 0,
  `alliance` tinyint NOT NULL DEFAULT -1,
  `rivals` tinyint NULL DEFAULT -1,
  `war1` tinyint NOT NULL DEFAULT 0,
  `war2` tinyint NOT NULL DEFAULT 0,
  `war3` tinyint NOT NULL DEFAULT 0,
  `rank_9mm` tinyint NOT NULL DEFAULT 1,
  `rank_sdpistol` tinyint NOT NULL DEFAULT 1,
  `rank_deagle` tinyint NOT NULL DEFAULT 2,
  `rank_shotgun` tinyint NOT NULL DEFAULT 1,
  `rank_spas12` tinyint NOT NULL DEFAULT 4,
  `rank_sawnoff` tinyint NOT NULL DEFAULT 4,
  `rank_tec9` tinyint NOT NULL DEFAULT 1,
  `rank_uzi` tinyint NOT NULL DEFAULT 1,
  `rank_mp5` tinyint NOT NULL DEFAULT 2,
  `rank_ak47` tinyint NOT NULL DEFAULT 3,
  `rank_m4` tinyint NOT NULL DEFAULT 4,
  `rank_rifle` tinyint NOT NULL DEFAULT 2,
  `rank_sniper` tinyint NOT NULL DEFAULT 5,
  `rank_molotov` tinyint NOT NULL DEFAULT 5,
  `rank_vest` tinyint NOT NULL DEFAULT 0
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of gangs
-- ----------------------------

-- ----------------------------
-- Table structure for gangskins
-- ----------------------------
DROP TABLE IF EXISTS `gangskins`;
CREATE TABLE `gangskins`  (
  `id` tinyint NULL DEFAULT NULL,
  `slot` tinyint NULL DEFAULT NULL,
  `skinid` smallint NULL DEFAULT NULL,
  UNIQUE INDEX `id`(`id` ASC, `slot` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of gangskins
-- ----------------------------

-- ----------------------------
-- Table structure for gangtags
-- ----------------------------
DROP TABLE IF EXISTS `gangtags`;
CREATE TABLE `gangtags`  (
  `gangid` int NOT NULL,
  `text` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `fontid` int NOT NULL,
  `pname` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `color` int NOT NULL,
  `x` float(11, 4) NOT NULL DEFAULT 0.0000,
  `y` float(11, 4) NOT NULL DEFAULT 0.0000,
  `z` float(11, 4) NOT NULL DEFAULT 0.0000,
  `rx` float(11, 4) NOT NULL DEFAULT 0.0000,
  `ry` float(11, 4) NOT NULL DEFAULT 0.0000,
  `rz` float(11, 4) NOT NULL DEFAULT 0.0000,
  `ID` int NOT NULL,
  `pdbid` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of gangtags
-- ----------------------------

-- ----------------------------
-- Table structure for garages
-- ----------------------------
DROP TABLE IF EXISTS `garages`;
CREATE TABLE `garages`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `ownerid` int NULL DEFAULT 0,
  `owner` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `type` tinyint(1) NULL DEFAULT 0,
  `price` int NULL DEFAULT 0,
  `locked` tinyint(1) NULL DEFAULT 0,
  `timestamp` int NULL DEFAULT 0,
  `pos_x` float NULL DEFAULT 0,
  `pos_y` float NULL DEFAULT 0,
  `pos_z` float NULL DEFAULT 0,
  `pos_a` float NULL DEFAULT 0,
  `exit_x` float NULL DEFAULT 0,
  `exit_y` float NULL DEFAULT 0,
  `exit_z` float NULL DEFAULT 0,
  `exit_a` float NULL DEFAULT 0,
  `world` int NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `id`(`id` ASC) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 4 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of garages
-- ----------------------------

-- ----------------------------
-- Table structure for gates
-- ----------------------------
DROP TABLE IF EXISTS `gates`;
CREATE TABLE `gates`  (
  `ID` int NOT NULL,
  `HID` int NOT NULL DEFAULT -1,
  `Speed` float NOT NULL DEFAULT 10,
  `Range` float NOT NULL DEFAULT 10,
  `Model` int NOT NULL DEFAULT 18631,
  `VW` int NOT NULL DEFAULT 0,
  `Int` int NOT NULL DEFAULT 0,
  `Pass` varchar(24) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `PosX` float NOT NULL DEFAULT 0,
  `PosY` float NOT NULL DEFAULT 0,
  `PosZ` float NOT NULL DEFAULT 0,
  `RotX` float NOT NULL DEFAULT 0,
  `RotY` float NOT NULL DEFAULT 0,
  `RotZ` float NOT NULL DEFAULT 0,
  `PosXM` float NOT NULL DEFAULT 0,
  `PosYM` float NOT NULL DEFAULT 0,
  `PosZM` float NOT NULL DEFAULT 0,
  `RotXM` float NOT NULL DEFAULT 0,
  `RotYM` float NOT NULL DEFAULT 0,
  `RotZM` float NOT NULL DEFAULT 0,
  `Allegiance` int NOT NULL DEFAULT 0,
  `GroupType` int NOT NULL DEFAULT 0,
  `GroupID` int NOT NULL DEFAULT -1,
  `GangID` int NOT NULL DEFAULT -1,
  `RenderHQ` int NOT NULL DEFAULT 1,
  `Timer` int NOT NULL DEFAULT 0,
  `Automate` int NOT NULL,
  `Locked` int NOT NULL,
  `TIndex` int NOT NULL,
  `TModel` int NOT NULL,
  `TColor` int NOT NULL,
  `Facility` int NOT NULL,
  `TTXD` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `TTexture` varchar(42) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of gates
-- ----------------------------

-- ----------------------------
-- Table structure for graffiti
-- ----------------------------
DROP TABLE IF EXISTS `graffiti`;
CREATE TABLE `graffiti`  (
  `graffitiText` varchar(40) CHARACTER SET latin1 COLLATE latin1_danish_ci NULL DEFAULT NULL,
  `graffitiID` int NOT NULL AUTO_INCREMENT,
  `graffitiX` float NULL DEFAULT 0,
  `graffitiY` float NULL DEFAULT 0,
  `graffitiZ` float NULL DEFAULT 0,
  `graffitiAngle` int NULL DEFAULT 0,
  `graffitiColor` int NULL DEFAULT 0,
  PRIMARY KEY (`graffitiID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 4 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of graffiti
-- ----------------------------

-- ----------------------------
-- Table structure for gunracks
-- ----------------------------
DROP TABLE IF EXISTS `gunracks`;
CREATE TABLE `gunracks`  (
  `rackID` int NOT NULL AUTO_INCREMENT,
  `rackHouse` int NULL DEFAULT 0,
  `rackX` float NULL DEFAULT 0,
  `rackY` float NULL DEFAULT 0,
  `rackZ` float NULL DEFAULT 0,
  `rackA` float NULL DEFAULT 0,
  `rackInterior` int NULL DEFAULT 0,
  `rackWorld` int NULL DEFAULT 0,
  `rackWeapon1` int NULL DEFAULT 0,
  `rackAmmo1` int NULL DEFAULT 0,
  `rackWeapon2` int NULL DEFAULT 0,
  `rackAmmo2` int NULL DEFAULT 0,
  `rackWeapon3` int NULL DEFAULT 0,
  `rackAmmo3` int NULL DEFAULT 0,
  `rackWeapon4` int NULL DEFAULT 0,
  `rackAmmo4` int NULL DEFAULT 0,
  PRIMARY KEY (`rackID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of gunracks
-- ----------------------------

-- ----------------------------
-- Table structure for houses
-- ----------------------------
DROP TABLE IF EXISTS `houses`;
CREATE TABLE `houses`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `ownerid` int NULL DEFAULT 0,
  `owner` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'Nobody',
  `type` tinyint NULL DEFAULT 0,
  `price` int NULL DEFAULT 0,
  `rentprice` int NULL DEFAULT 0,
  `level` tinyint NULL DEFAULT 0,
  `locked` tinyint(1) NULL DEFAULT 0,
  `timestamp` int NULL DEFAULT 0,
  `pos_x` float NULL DEFAULT 0,
  `pos_y` float NULL DEFAULT 0,
  `pos_z` float NULL DEFAULT 0,
  `pos_a` float NULL DEFAULT 0,
  `int_x` float NULL DEFAULT 0,
  `int_y` float NULL DEFAULT 0,
  `int_z` float NULL DEFAULT 0,
  `int_a` float NULL DEFAULT 0,
  `interior` tinyint NULL DEFAULT 0,
  `world` int NULL DEFAULT 0,
  `outsideint` int NULL DEFAULT 0,
  `outsidevw` int NULL DEFAULT 0,
  `cash` int NULL DEFAULT 0,
  `materials` int NULL DEFAULT 0,
  `weed` int NULL DEFAULT 0,
  `cocaine` int NULL DEFAULT 0,
  `meth` int NULL DEFAULT 0,
  `painkillers` int NULL DEFAULT 0,
  `weapon_1` tinyint NULL DEFAULT 0,
  `weapon_2` tinyint NULL DEFAULT 0,
  `weapon_3` tinyint NULL DEFAULT 0,
  `weapon_4` tinyint NULL DEFAULT 0,
  `weapon_5` tinyint NULL DEFAULT 0,
  `weapon_6` tinyint NULL DEFAULT 0,
  `weapon_7` tinyint NULL DEFAULT 0,
  `weapon_8` tinyint NULL DEFAULT 0,
  `weapon_9` tinyint NULL DEFAULT 0,
  `weapon_10` tinyint NULL DEFAULT 0,
  `ammo_1` smallint NULL DEFAULT 0,
  `ammo_2` smallint NULL DEFAULT 0,
  `ammo_3` smallint NULL DEFAULT 0,
  `ammo_4` smallint NULL DEFAULT 0,
  `ammo_5` smallint NULL DEFAULT 0,
  `ammo_6` tinyint NULL DEFAULT 0,
  `ammo_7` tinyint NULL DEFAULT 0,
  `ammo_8` tinyint NULL DEFAULT 0,
  `ammo_9` tinyint NULL DEFAULT 0,
  `ammo_10` tinyint NULL DEFAULT 0,
  `pistolammo` smallint NULL DEFAULT 0,
  `shotgunammo` smallint NULL DEFAULT 0,
  `smgammo` smallint NULL DEFAULT 0,
  `arammo` smallint NULL DEFAULT 0,
  `rifleammo` smallint NULL DEFAULT 0,
  `hpammo` smallint NULL DEFAULT 0,
  `poisonammo` smallint NULL DEFAULT 0,
  `fmjammo` smallint NULL DEFAULT 0,
  `delivery` tinyint NULL DEFAULT 1,
  `lights` tinyint(1) NULL DEFAULT 1,
  `freeze` tinyint(1) NULL DEFAULT 1,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 106 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of houses
-- ----------------------------

-- ----------------------------
-- Table structure for kills
-- ----------------------------
DROP TABLE IF EXISTS `kills`;
CREATE TABLE `kills`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `killer_uid` int NULL DEFAULT NULL,
  `target_uid` int NULL DEFAULT NULL,
  `killer` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `target` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `reason` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `date` datetime NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 2790 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of kills
-- ----------------------------

-- ----------------------------
-- Table structure for landobjects
-- ----------------------------
DROP TABLE IF EXISTS `landobjects`;
CREATE TABLE `landobjects`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `landid` int NULL DEFAULT NULL,
  `modelid` smallint NULL DEFAULT NULL,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `price` int NULL DEFAULT NULL,
  `pos_x` float NULL DEFAULT NULL,
  `pos_y` float NULL DEFAULT NULL,
  `pos_z` float NULL DEFAULT NULL,
  `rot_x` float NULL DEFAULT NULL,
  `rot_y` float NULL DEFAULT NULL,
  `rot_z` float NULL DEFAULT NULL,
  `door_opened` tinyint(1) NULL DEFAULT 0,
  `door_locked` tinyint(1) NULL DEFAULT 0,
  `move_x` float NULL DEFAULT 0,
  `move_y` float NULL DEFAULT 0,
  `move_z` float NULL DEFAULT 0,
  `move_rx` float NULL DEFAULT 0,
  `move_ry` float NULL DEFAULT 0,
  `move_rz` float NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 16905 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of landobjects
-- ----------------------------

-- ----------------------------
-- Table structure for lands
-- ----------------------------
DROP TABLE IF EXISTS `lands`;
CREATE TABLE `lands`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `ownerid` int NULL DEFAULT 0,
  `owner` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'Nobody',
  `price` int NULL DEFAULT 0,
  `min_x` float NULL DEFAULT 0,
  `min_y` float NULL DEFAULT 0,
  `max_x` float NULL DEFAULT 0,
  `max_y` float NULL DEFAULT 0,
  `height` float NULL DEFAULT 0,
  `ltext_x` float NULL DEFAULT 0,
  `ltext_y` float NULL DEFAULT 0,
  `ltext_z` float NULL DEFAULT 0,
  `level` tinyint NULL DEFAULT 0,
  `factiontype` tinyint NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 170 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of lands
-- ----------------------------

-- ----------------------------
-- Table structure for locations
-- ----------------------------
DROP TABLE IF EXISTS `locations`;
CREATE TABLE `locations`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `pos_x` float NOT NULL,
  `pos_y` float NOT NULL,
  `pos_z` float NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 37 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of locations
-- ----------------------------

-- ----------------------------
-- Table structure for log_admin
-- ----------------------------
DROP TABLE IF EXISTS `log_admin`;
CREATE TABLE `log_admin`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 6112 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_admin
-- ----------------------------
INSERT INTO `log_admin` VALUES (6109, '2021-06-24 15:44:24', 'Kiet_Le (uid: 35) has made Kiet_Le (uid: 35) a dynamic admin.');
INSERT INTO `log_admin` VALUES (6110, '2021-06-24 17:06:44', 'Kiet_Le (uid: 35) has made Kiet_Le (uid: 35) a faction moderator.');
INSERT INTO `log_admin` VALUES (6111, '2022-04-18 13:58:17', 'Kiet_Le (uid: 36) da chi dinh Kiet_Le (uid: 36) a dynamic admin.');

-- ----------------------------
-- Table structure for log_bans
-- ----------------------------
DROP TABLE IF EXISTS `log_bans`;
CREATE TABLE `log_bans`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `uid` int NULL DEFAULT NULL,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 266 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_bans
-- ----------------------------

-- ----------------------------
-- Table structure for log_cheat
-- ----------------------------
DROP TABLE IF EXISTS `log_cheat`;
CREATE TABLE `log_cheat`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 289 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_cheat
-- ----------------------------
INSERT INTO `log_cheat` VALUES (70, '2017-07-10 02:49:32', 'Ronald_Eastwood (uid: 634) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (71, '2017-07-10 02:55:32', 'Ronald_Eastwood (uid: 634) had a desynced Desert Eagle with 170 ammunition.');
INSERT INTO `log_cheat` VALUES (72, '2017-07-11 07:12:41', 'Jenice_Salvatore (uid: 632) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (73, '2017-07-12 00:49:03', 'Borgy_Salvatore (uid: 631) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (74, '2017-07-12 01:18:46', 'Xac_Uley (uid: 667) possibly speedhacked, speed: 360.8 km/h');
INSERT INTO `log_cheat` VALUES (75, '2017-07-12 01:18:47', 'Xac_Uley (uid: 667) possibly speedhacked, speed: 350.2 km/h');
INSERT INTO `log_cheat` VALUES (76, '2017-07-12 04:24:29', 'Borgy_salvatore (uid: 631) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (77, '2017-07-12 04:24:43', 'Daniel_Villanueva (uid: 648) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (78, '2017-07-12 05:17:48', 'Justine_Salvatore (uid: 649) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (79, '2017-07-12 10:16:39', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 64.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (80, '2017-07-12 10:17:10', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 64.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (81, '2017-07-12 10:21:47', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 0.00, new: 64.00)');
INSERT INTO `log_cheat` VALUES (82, '2017-07-12 10:21:47', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 73.00)');
INSERT INTO `log_cheat` VALUES (83, '2017-07-12 10:22:00', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 73.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (84, '2017-07-12 10:23:37', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 64.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (85, '2017-07-12 10:24:27', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 53.00)');
INSERT INTO `log_cheat` VALUES (86, '2017-07-12 10:24:28', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 64.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (87, '2017-07-12 10:29:28', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 0.00, new: 64.00)');
INSERT INTO `log_cheat` VALUES (88, '2017-07-12 10:29:39', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (89, '2017-07-12 10:29:39', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 64.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (90, '2017-07-12 11:36:29', 'Aziz_Hfaidh (uid: 662) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (91, '2017-07-13 02:51:53', 'Jason_Wox (uid: 675) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (92, '2017-07-13 06:58:19', 'James_Garcia (uid: 676) had a desynced Desert Eagle with 131 ammunition.');
INSERT INTO `log_cheat` VALUES (93, '2017-07-13 07:52:46', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (94, '2017-07-13 07:52:47', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 59.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (95, '2017-07-13 07:57:47', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 0.00, new: 59.00)');
INSERT INTO `log_cheat` VALUES (96, '2017-07-13 07:58:04', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (97, '2017-07-13 07:58:07', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 59.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (98, '2017-07-13 08:03:16', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 0.00, new: 59.00)');
INSERT INTO `log_cheat` VALUES (99, '2017-07-13 08:09:54', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (100, '2017-07-13 08:13:42', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (101, '2017-07-13 08:17:24', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (102, '2017-07-14 03:38:39', 'Chris_Pine (uid: 681) had a desynced Desert Eagle with 114 ammunition.');
INSERT INTO `log_cheat` VALUES (103, '2017-07-14 03:38:39', 'Chris_Pine (uid: 681) had a desynced Desert Eagle with 114 ammunition.');
INSERT INTO `log_cheat` VALUES (104, '2017-07-14 03:38:40', 'Chris_Pine (uid: 681) had a desynced Desert Eagle with 114 ammunition.');
INSERT INTO `log_cheat` VALUES (105, '2017-07-14 03:38:59', 'Chris_Pine (uid: 681) had a desynced Desert Eagle with 114 ammunition.');
INSERT INTO `log_cheat` VALUES (106, '2017-07-14 08:22:15', 'Fares_snoop (uid: 687) possibly speedhacked, speed: 362.3 km/h');
INSERT INTO `log_cheat` VALUES (107, '2017-07-14 08:22:16', 'Fares_snoop (uid: 687) possibly speedhacked, speed: 361.9 km/h');
INSERT INTO `log_cheat` VALUES (108, '2017-07-14 08:22:17', 'Fares_snoop (uid: 687) possibly speedhacked, speed: 362.1 km/h');
INSERT INTO `log_cheat` VALUES (109, '2017-07-14 08:22:18', 'Fares_snoop (uid: 687) possibly speedhacked, speed: 362.1 km/h');
INSERT INTO `log_cheat` VALUES (110, '2017-07-14 22:40:03', 'Asykon_Wolf (uid: 699) possibly speedhacked, speed: 361.5 km/h');
INSERT INTO `log_cheat` VALUES (111, '2017-07-14 22:40:04', 'Asykon_Wolf (uid: 699) possibly speedhacked, speed: 361.6 km/h');
INSERT INTO `log_cheat` VALUES (112, '2017-07-14 22:40:07', 'Asykon_Wolf (uid: 699) possibly speedhacked, speed: 361.7 km/h');
INSERT INTO `log_cheat` VALUES (113, '2017-07-14 22:40:08', 'Asykon_Wolf (uid: 699) possibly speedhacked, speed: 361.6 km/h');
INSERT INTO `log_cheat` VALUES (114, '2017-07-15 00:56:48', 'Vincent_Shock (uid: 707) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (115, '2018-04-03 14:12:22', 'Lan_Smoke (uid: 789) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (116, '2018-04-03 14:14:56', 'Poseidon_Vincre (uid: 808) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (117, '2018-04-03 14:14:56', 'Lan_Smoke (uid: 789) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (118, '2018-04-03 14:14:56', 'Clark_savage (uid: 729) possibly hacked armor. (old: 0.00, new: 50.00)');
INSERT INTO `log_cheat` VALUES (119, '2018-04-03 14:18:30', 'Poseidon_Vincre (uid: 808) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (120, '2018-04-03 14:20:29', 'Lan_Smoke (uid: 789) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (121, '2018-09-25 14:33:47', 'Franco_V_Shadow (uid: 822) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (122, '2018-09-26 11:55:52', 'dean_parker (uid: 846) possibly speedhacked, speed: 350.1 km/h');
INSERT INTO `log_cheat` VALUES (123, '2018-09-26 11:55:54', 'dean_parker (uid: 846) possibly speedhacked, speed: 378.7 km/h');
INSERT INTO `log_cheat` VALUES (124, '2018-09-26 11:55:55', 'dean_parker (uid: 846) possibly speedhacked, speed: 399.9 km/h');
INSERT INTO `log_cheat` VALUES (125, '2018-09-26 11:55:56', 'dean_parker (uid: 846) possibly speedhacked, speed: 415.7 km/h');
INSERT INTO `log_cheat` VALUES (126, '2018-09-26 12:56:44', 'John_Bud (uid: 844) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (127, '2018-09-26 13:06:37', 'Jax_Ortega (uid: 831) possibly hacked armor. (old: 0.00, new: 1.00)');
INSERT INTO `log_cheat` VALUES (128, '2018-09-26 13:07:28', 'Jax_Ortega (uid: 831) possibly hacked armor. (old: 0.00, new: 7.00)');
INSERT INTO `log_cheat` VALUES (129, '2018-09-26 17:56:20', 'Cv_Jeremy (uid: 851) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (130, '2018-09-27 08:56:49', 'kervin_pogi (uid: 847) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (131, '2018-09-27 09:33:59', 'Klos_B_Varios (uid: 853) possibly hacked armor. (old: 58.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (132, '2018-09-28 06:05:01', 'Yuri_V_Gwapigs (uid: 863) had a desynced Desert Eagle with 19942 ammunition.');
INSERT INTO `log_cheat` VALUES (133, '2018-09-28 13:48:41', 'Klos_B_Varios (uid: 853) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (134, '2018-09-28 18:05:29', 'Cv_jeremiah (uid: 851) possibly hacked armor. (old: 47.00, new: 168.00)');
INSERT INTO `log_cheat` VALUES (135, '2018-09-29 05:55:52', 'Adolf_Jones (uid: 892) possibly hacked armor. (old: 183.00, new: 208.00)');
INSERT INTO `log_cheat` VALUES (136, '2018-09-29 06:00:14', 'joseff_ocampo (uid: 890) possibly hacked armor. (old: 25.00, new: 207.00)');
INSERT INTO `log_cheat` VALUES (137, '2018-09-29 06:05:08', 'Adolf_Jones (uid: 892) possibly hacked armor. (old: 23.00, new: 238.00)');
INSERT INTO `log_cheat` VALUES (138, '2018-09-30 03:45:24', 'Jack_Park (uid: 873) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (139, '2018-09-30 04:15:37', 'Alvina_Love (uid: 907) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (140, '2018-09-30 08:02:48', 'John_Fabian (uid: 916) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (141, '2018-09-30 08:48:37', 'Yuri_V_Bud (uid: 863) had a desynced Desert Eagle with 19991 ammunition.');
INSERT INTO `log_cheat` VALUES (142, '2018-09-30 09:03:02', 'Ken_Chan (uid: 867) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (143, '2018-09-30 11:54:10', 'joseph_jumadas (uid: 929) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (144, '2018-09-30 13:23:31', 'Lucid_Dreams (uid: 894) possibly hacked armor. (old: 7.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (145, '2018-09-30 13:39:13', 'Drake_Freeman (uid: 937) had a desynced Desert Eagle with 19994 ammunition.');
INSERT INTO `log_cheat` VALUES (146, '2018-09-30 16:28:13', 'Daniel_Sultan (uid: 928) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (147, '2018-10-01 04:29:58', 'richard_dreams (uid: 930) possibly hacked armor. (old: 0.00, new: 53.00)');
INSERT INTO `log_cheat` VALUES (148, '2018-10-01 07:26:35', 'Dante_Ruiz (uid: 956) had a desynced Combat Shotgun with 145 ammunition.');
INSERT INTO `log_cheat` VALUES (149, '2018-10-01 07:26:35', 'Dante_Ruiz (uid: 956) had a desynced Nite Stick with 170 ammunition.');
INSERT INTO `log_cheat` VALUES (150, '2018-10-01 07:26:36', 'Dante_Ruiz (uid: 956) had a desynced Combat Shotgun with 145 ammunition.');
INSERT INTO `log_cheat` VALUES (151, '2018-10-01 07:34:47', 'Dante_Ruiz (uid: 956) possibly speedhacked, speed: 359.5 km/h');
INSERT INTO `log_cheat` VALUES (152, '2018-10-01 07:45:31', 'Jeff_Walker (uid: 949) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (153, '2018-10-01 07:54:30', 'van_wise (uid: 958) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (154, '2018-10-01 12:52:33', 'Alex_Freeman (uid: 967) had a desynced Pool Cue with 48 ammunition.');
INSERT INTO `log_cheat` VALUES (155, '2018-10-01 12:53:14', 'Alex_Freeman (uid: 967) had a desynced Pool Cue with 48 ammunition.');
INSERT INTO `log_cheat` VALUES (156, '2018-10-01 12:53:20', 'Alex_Freeman (uid: 967) had a desynced Pool Cue with 48 ammunition.');
INSERT INTO `log_cheat` VALUES (157, '2018-10-01 12:53:21', 'Alex_Freeman (uid: 967) had a desynced Pool Cue with 48 ammunition.');
INSERT INTO `log_cheat` VALUES (158, '2018-10-01 14:07:58', 'Lucid_Dreams (uid: 945) possibly hacked armor. (old: 98.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (159, '2018-10-02 03:59:34', 'Daniel_Dreams (uid: 928) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (160, '2018-10-02 04:03:09', 'Lian_Dreams (uid: 931) possibly hacked armor. (old: 0.00, new: 20.00)');
INSERT INTO `log_cheat` VALUES (161, '2018-10-02 04:44:24', 'Sophia_Bud (uid: 881) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (162, '2018-10-02 05:20:55', 'John_Dreams (uid: 916) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (163, '2018-10-02 06:26:40', 'kevin_k_banks (uid: 910) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (164, '2018-10-02 11:06:00', 'Elijah_Montefalco (uid: 964) possibly hacked armor. (old: 0.00, new: 3.00)');
INSERT INTO `log_cheat` VALUES (165, '2018-10-03 04:43:05', 'Lian_Dreams (uid: 931) possibly speedhacked, speed: 361.7 km/h');
INSERT INTO `log_cheat` VALUES (166, '2018-10-03 04:43:06', 'Lian_Dreams (uid: 931) possibly speedhacked, speed: 361.7 km/h');
INSERT INTO `log_cheat` VALUES (167, '2018-10-03 09:03:04', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (168, '2018-10-03 09:12:17', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (169, '2018-10-03 09:15:49', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (170, '2018-10-03 09:17:22', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 60.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (171, '2018-10-03 09:17:35', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 53.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (172, '2018-10-03 09:20:59', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (173, '2018-10-03 09:54:35', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (174, '2018-10-03 10:03:55', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (175, '2018-10-03 10:19:59', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (176, '2018-10-03 10:33:09', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (177, '2018-10-03 10:37:04', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (178, '2018-10-03 12:38:49', 'Lrizz_Devil (uid: 903) possibly hacked armor. (old: 0.00, new: 7.00)');
INSERT INTO `log_cheat` VALUES (179, '2018-10-04 06:58:31', 'Ken_Dreams (uid: 996) possibly speedhacked, speed: 362.2 km/h');
INSERT INTO `log_cheat` VALUES (180, '2018-10-04 10:27:54', 'Ken_Dreams (uid: 996) possibly hacked armor. (old: 7.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (181, '2018-10-05 02:20:59', 'Ken_Dreams (uid: 996) possibly speedhacked, speed: 360.7 km/h');
INSERT INTO `log_cheat` VALUES (182, '2018-10-05 02:28:44', 'Dave_Dreams (uid: 935) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (183, '2018-10-05 02:30:25', 'Dave_Dreams (uid: 935) possibly hacked armor. (old: 53.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (184, '2018-10-05 02:33:37', 'Ken_Dreams (uid: 996) possibly speedhacked, speed: 361.4 km/h');
INSERT INTO `log_cheat` VALUES (185, '2018-10-05 02:58:11', 'Dave_Dreams (uid: 935) possibly hacked armor. (old: 51.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (186, '2018-10-21 02:45:16', 'Trisha_Maxine (uid: 1041) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (187, '2018-10-21 06:24:02', 'Jeff_Walker (uid: 1047) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (188, '2018-10-25 14:42:24', 'Chuck_Taylor (uid: 1090) had a desynced UZI with 19998 ammunition.');
INSERT INTO `log_cheat` VALUES (189, '2018-10-25 14:49:07', 'Chuck_Taylor (uid: 1090) had a desynced M4 with 19999 ammunition.');
INSERT INTO `log_cheat` VALUES (190, '2018-10-25 15:26:17', 'Perfecto_Slash (uid: 1098) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (191, '2018-10-26 01:43:22', 'Daniel_Corman (uid: 1075) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (192, '2018-10-26 04:30:52', 'Ashley_Zhin (uid: 1117) possibly hacked armor. (old: 0.00, new: 97.00)');
INSERT INTO `log_cheat` VALUES (193, '2018-10-26 05:21:38', 'Sophia_Rolex (uid: 1125) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (194, '2018-10-26 06:51:47', 'Jhon_Carter (uid: 1126) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (195, '2018-10-26 10:58:10', 'Leonidas_Savage (uid: 1146) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (196, '2018-10-26 11:18:20', 'mustafa_abir (uid: 1127) possibly hacked armor. (old: 0.00, new: 90.00)');
INSERT INTO `log_cheat` VALUES (197, '2018-10-26 13:49:35', 'Clark_Chives (uid: 1143) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (198, '2018-10-26 14:23:30', 'Prince_Fabian (uid: 1084) had a desynced Desert Eagle with 19999 ammunition.');
INSERT INTO `log_cheat` VALUES (199, '2018-10-26 14:31:17', 'Max_S_Schneider (uid: 1153) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (200, '2018-10-26 14:42:10', 'Troi_Miller (uid: 1167) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (201, '2018-10-27 03:58:31', 'Mea_Black (uid: 1070) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (202, '2018-10-27 17:26:20', 'Pritz_G_Ramirez (uid: 1081) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (203, '2018-10-28 06:17:07', 'Kentoy_Vincre (uid: 1195) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (204, '2018-10-28 06:25:50', 'Pritz_G_Ramirez (uid: 1081) possibly hacked armor. (old: 0.00, new: 95.00)');
INSERT INTO `log_cheat` VALUES (205, '2018-10-28 06:36:34', 'Kore_G_Ramirez (uid: 1192) possibly hacked armor. (old: 0.00, new: 50.00)');
INSERT INTO `log_cheat` VALUES (206, '2018-10-28 09:40:04', 'Timmy_Powell (uid: 1115) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (207, '2018-10-28 10:16:33', 'Justin_Jhay (uid: 1068) possibly speedhacked, speed: 362.5 km/h');
INSERT INTO `log_cheat` VALUES (208, '2018-10-28 10:16:34', 'Justin_Jhay (uid: 1068) possibly speedhacked, speed: 362.5 km/h');
INSERT INTO `log_cheat` VALUES (209, '2018-10-28 10:16:35', 'Justin_Jhay (uid: 1068) possibly speedhacked, speed: 362.5 km/h');
INSERT INTO `log_cheat` VALUES (210, '2018-10-28 10:16:54', 'Justin_Jhay (uid: 1068) possibly speedhacked, speed: 359.6 km/h');
INSERT INTO `log_cheat` VALUES (211, '2018-10-28 13:13:22', 'john_richard_don (uid: 1213) possibly hacked armor. (old: 92.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (212, '2018-10-28 13:17:34', 'Pritz_G_Ramirez (uid: 1081) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (213, '2018-10-29 01:42:14', 'Eurie_G_Ramirez (uid: 1198) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (214, '2018-10-29 04:17:11', 'Daffa_Adaki (uid: 1222) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (215, '2018-10-29 11:48:34', 'Prince_Wise (uid: 1129) possibly hacked armor. (old: 25.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (216, '2018-10-30 02:17:51', 'Lenard_Lean (uid: 1231) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (217, '2018-10-30 03:51:14', 'Smith_Johnson (uid: 1233) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (218, '2018-10-30 04:35:43', 'Jack_Dein (uid: 1236) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (219, '2018-10-30 05:04:07', 'Steve_Jobs (uid: 1073) possibly hacked armor. (old: 7.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (220, '2018-10-30 05:07:20', 'Steve_Jobs (uid: 1073) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (221, '2018-10-30 05:08:36', 'Steve_Jobs (uid: 1073) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (222, '2018-10-30 05:25:11', 'prince_wise (uid: 1129) had a desynced Sniper Rifle with 19999 ammunition.');
INSERT INTO `log_cheat` VALUES (223, '2018-10-30 05:32:45', 'prince_wise (uid: 1129) possibly hacked armor. (old: 0.00, new: 90.00)');
INSERT INTO `log_cheat` VALUES (224, '2018-10-30 11:22:33', 'Conner_Lacroix (uid: 1079) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (225, '2018-10-30 11:22:33', 'Ocir_Lacroix (uid: 1212) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (226, '2018-10-30 11:27:42', 'Conner_Lacroix (uid: 1079) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (227, '2018-10-30 11:35:08', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 53.00)');
INSERT INTO `log_cheat` VALUES (228, '2018-10-30 11:42:54', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (229, '2018-10-30 11:49:41', 'Conner_Lacroix (uid: 1079) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (230, '2018-10-30 12:31:48', 'Lorence_X_Marks (uid: 1232) possibly hacked armor. (old: 2.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (231, '2018-10-30 14:18:01', 'lance_v_shadow (uid: 1211) possibly hacked armor. (old: 0.00, new: 7.00)');
INSERT INTO `log_cheat` VALUES (232, '2018-10-31 03:53:25', 'Genz_T_Slice (uid: 1085) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (233, '2018-10-31 05:07:49', 'Rhods_Fabian (uid: 1067) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (234, '2018-10-31 05:13:48', 'Rhods_Fabian (uid: 1067) possibly hacked armor. (old: 0.00, new: 80.00)');
INSERT INTO `log_cheat` VALUES (235, '2018-10-31 07:10:20', 'Adrian_Pascual (uid: 1270) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (236, '2018-10-31 07:10:31', 'Adrian_Pascual (uid: 1270) had a desynced Baseball Bat with 174 ammunition.');
INSERT INTO `log_cheat` VALUES (237, '2018-10-31 07:10:32', 'Adrian_Pascual (uid: 1270) had a desynced Baseball Bat with 174 ammunition.');
INSERT INTO `log_cheat` VALUES (238, '2018-10-31 07:57:24', 'Genz_T_Slice (uid: 1085) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (239, '2018-10-31 08:10:19', 'Drizz_Powell (uid: 1273) had a desynced Fire Extinguisher with 19999 ammunition.');
INSERT INTO `log_cheat` VALUES (240, '2018-10-31 08:19:35', 'Christo_Valentino (uid: 1275) possibly hacked armor. (old: 30.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (241, '2018-10-31 09:27:10', 'Seteven_William (uid: 1274) had a desynced Sawn-off Shotgun with 19999 ammunition.');
INSERT INTO `log_cheat` VALUES (242, '2018-10-31 10:48:08', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 22.00)');
INSERT INTO `log_cheat` VALUES (243, '2018-10-31 10:48:08', 'Genz_T_Slice (uid: 1085) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (244, '2018-10-31 10:48:08', 'Daniel_Corman (uid: 1075) possibly hacked armor. (old: 0.00, new: 75.00)');
INSERT INTO `log_cheat` VALUES (245, '2018-10-31 10:52:12', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 22.00)');
INSERT INTO `log_cheat` VALUES (246, '2018-10-31 12:37:17', 'Zac_G_Hiest (uid: 1103) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (247, '2018-10-31 14:23:20', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 12.00)');
INSERT INTO `log_cheat` VALUES (248, '2018-10-31 14:23:27', 'James_Foxton (uid: 1140) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (249, '2018-11-01 03:23:25', 'Sophia_Rolex (uid: 1125) had a desynced Sniper Rifle with 19999 ammunition.');
INSERT INTO `log_cheat` VALUES (250, '2018-11-01 03:23:35', 'Kai_Slash (uid: 1297) possibly hacked armor. (old: 14.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (251, '2018-11-01 04:02:32', 'Christopher_S_Zhin (uid: 1298) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (252, '2018-11-01 05:11:34', 'Kyle_Wazowski (uid: 1303) possibly hacked armor. (old: 0.00, new: 30.00)');
INSERT INTO `log_cheat` VALUES (253, '2018-11-01 06:01:26', 'Christo_Valentino (uid: 1275) possibly hacked armor. (old: 98.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (254, '2018-11-01 06:15:58', 'Rara_William (uid: 1281) possibly hacked armor. (old: 7.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (255, '2018-11-01 06:17:57', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 75.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (256, '2018-11-01 06:20:21', 'Lucky_One (uid: 1208) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (257, '2018-11-01 07:39:38', 'Rara_William (uid: 1281) possibly hacked armor. (old: 0.00, new: 98.00)');
INSERT INTO `log_cheat` VALUES (258, '2018-11-01 09:16:41', 'Lely_Maddox (uid: 1316) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (259, '2018-11-01 09:47:17', 'Kai_Fabians (uid: 1297) possibly speedhacked, speed: 362.2 km/h');
INSERT INTO `log_cheat` VALUES (260, '2018-11-01 09:48:07', 'Kai_Fabians (uid: 1297) possibly speedhacked, speed: 361.1 km/h');
INSERT INTO `log_cheat` VALUES (261, '2018-11-01 09:48:08', 'Kai_Fabians (uid: 1297) possibly speedhacked, speed: 361.2 km/h');
INSERT INTO `log_cheat` VALUES (262, '2018-11-01 09:48:09', 'Kai_Fabians (uid: 1297) possibly speedhacked, speed: 361.2 km/h');
INSERT INTO `log_cheat` VALUES (263, '2018-11-01 10:06:00', 'Kyle_Fabian (uid: 1303) possibly hacked armor. (old: 0.00, new: 97.00)');
INSERT INTO `log_cheat` VALUES (264, '2018-11-01 10:09:30', 'Dixus_William (uid: 1282) possibly hacked armor. (old: 0.00, new: 95.00)');
INSERT INTO `log_cheat` VALUES (265, '2018-11-01 10:12:48', 'James_Foxton (uid: 1140) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (266, '2018-11-01 10:23:46', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 80.00)');
INSERT INTO `log_cheat` VALUES (267, '2018-11-01 10:35:11', 'Rara_Mutiara (uid: 1281) possibly hacked armor. (old: 0.00, new: 58.00)');
INSERT INTO `log_cheat` VALUES (268, '2018-11-01 11:17:46', 'Kyle_Fabian (uid: 1303) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (269, '2019-06-03 04:16:53', 'Albert_G_Street (uid: 1363) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (270, '2019-06-03 04:58:55', 'Jaim_Desanta (uid: 1330) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (271, '2019-06-03 05:18:57', 'Jaim_Desanta (uid: 1330) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (272, '2019-06-04 05:15:25', 'John_Turner (uid: 1347) possibly hacked armor. (old: 0.00, new: 58.00)');
INSERT INTO `log_cheat` VALUES (273, '2019-06-04 20:37:20', 'Hizashi_Nagato (uid: 1376) possibly hacked armor. (old: 0.00, new: 100.00)');
INSERT INTO `log_cheat` VALUES (274, '2019-06-05 11:42:45', 'Rodel_Nacianceno (uid: 8) possibly teleport hacked (distance: 130.3)');
INSERT INTO `log_cheat` VALUES (275, '2019-06-05 11:53:55', 'Shane_Amphibia (uid: 6) possibly teleport hacked (distance: 180.1)');
INSERT INTO `log_cheat` VALUES (276, '2019-06-05 11:56:14', 'Rodel_Nacianceno (uid: 8) possibly teleport hacked (distance: 181.4)');
INSERT INTO `log_cheat` VALUES (277, '2019-06-05 12:21:22', 'Rodel_Nacianceno (uid: 8) possibly teleport hacked (distance: 181.9)');
INSERT INTO `log_cheat` VALUES (278, '2019-06-05 18:34:43', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 116.1)');
INSERT INTO `log_cheat` VALUES (279, '2019-06-05 18:34:47', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 119.5)');
INSERT INTO `log_cheat` VALUES (280, '2019-06-05 18:34:50', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 113.7)');
INSERT INTO `log_cheat` VALUES (281, '2019-06-05 18:34:54', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 114.8)');
INSERT INTO `log_cheat` VALUES (282, '2019-06-05 18:34:58', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 114.2)');
INSERT INTO `log_cheat` VALUES (283, '2019-06-05 19:07:43', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 116.6)');
INSERT INTO `log_cheat` VALUES (284, '2019-06-06 09:02:29', 'Palawars_Akmel (uid: 20) possibly teleport hacked (distance: 424.9)');
INSERT INTO `log_cheat` VALUES (285, '2019-06-06 09:02:40', 'Palawars_Akmel (uid: 20) possibly teleport hacked (distance: 278.3)');
INSERT INTO `log_cheat` VALUES (286, '2019-06-06 09:02:55', 'Palawars_Akmel (uid: 20) possibly teleport hacked (distance: 124.5)');
INSERT INTO `log_cheat` VALUES (287, '2019-06-06 10:21:58', 'Jake_Smoke (uid: 21) possibly teleport hacked (distance: 115.9)');
INSERT INTO `log_cheat` VALUES (288, '2019-06-09 04:38:22', 'Ashley_Kuznetsova (uid: 33) possibly teleport hacked (distance: 123.5)');

-- ----------------------------
-- Table structure for log_contracts
-- ----------------------------
DROP TABLE IF EXISTS `log_contracts`;
CREATE TABLE `log_contracts`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 188 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_contracts
-- ----------------------------

-- ----------------------------
-- Table structure for log_cp
-- ----------------------------
DROP TABLE IF EXISTS `log_cp`;
CREATE TABLE `log_cp`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `executer` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL,
  `description` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL,
  `date` timestamp NULL DEFAULT current_timestamp,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_cp
-- ----------------------------

-- ----------------------------
-- Table structure for log_dicebet
-- ----------------------------
DROP TABLE IF EXISTS `log_dicebet`;
CREATE TABLE `log_dicebet`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 3657 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_dicebet
-- ----------------------------

-- ----------------------------
-- Table structure for log_faction
-- ----------------------------
DROP TABLE IF EXISTS `log_faction`;
CREATE TABLE `log_faction`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1488 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_faction
-- ----------------------------

-- ----------------------------
-- Table structure for log_gang
-- ----------------------------
DROP TABLE IF EXISTS `log_gang`;
CREATE TABLE `log_gang`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1338 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_gang
-- ----------------------------

-- ----------------------------
-- Table structure for log_give
-- ----------------------------
DROP TABLE IF EXISTS `log_give`;
CREATE TABLE `log_give`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 2099 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_give
-- ----------------------------

-- ----------------------------
-- Table structure for log_givecookie
-- ----------------------------
DROP TABLE IF EXISTS `log_givecookie`;
CREATE TABLE `log_givecookie`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 11 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_givecookie
-- ----------------------------

-- ----------------------------
-- Table structure for log_givegun
-- ----------------------------
DROP TABLE IF EXISTS `log_givegun`;
CREATE TABLE `log_givegun`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 23 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_givegun
-- ----------------------------

-- ----------------------------
-- Table structure for log_givemoney
-- ----------------------------
DROP TABLE IF EXISTS `log_givemoney`;
CREATE TABLE `log_givemoney`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 8 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_givemoney
-- ----------------------------
INSERT INTO `log_givemoney` VALUES (7, '2022-04-18 14:00:53', 'Kiet_Le (uid: 36) has used /givemoney to give $20000 to Kiet_Le (uid: 36).');

-- ----------------------------
-- Table structure for log_makeadmin
-- ----------------------------
DROP TABLE IF EXISTS `log_makeadmin`;
CREATE TABLE `log_makeadmin`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 27 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_makeadmin
-- ----------------------------
INSERT INTO `log_makeadmin` VALUES (26, '2021-06-24 15:43:52', 'Kiet_Le (uid: 35) set Kiet_Le\'s (uid: 35) admin level to 9');

-- ----------------------------
-- Table structure for log_makehelper
-- ----------------------------
DROP TABLE IF EXISTS `log_makehelper`;
CREATE TABLE `log_makehelper`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 7 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_makehelper
-- ----------------------------

-- ----------------------------
-- Table structure for log_namechanges
-- ----------------------------
DROP TABLE IF EXISTS `log_namechanges`;
CREATE TABLE `log_namechanges`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 412 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_namechanges
-- ----------------------------

-- ----------------------------
-- Table structure for log_namehistory
-- ----------------------------
DROP TABLE IF EXISTS `log_namehistory`;
CREATE TABLE `log_namehistory`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `uid` int NULL DEFAULT NULL,
  `oldname` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `newname` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `changedby` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `date` datetime NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 10 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_namehistory
-- ----------------------------

-- ----------------------------
-- Table structure for log_property
-- ----------------------------
DROP TABLE IF EXISTS `log_property`;
CREATE TABLE `log_property`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 807 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_property
-- ----------------------------

-- ----------------------------
-- Table structure for log_punishments
-- ----------------------------
DROP TABLE IF EXISTS `log_punishments`;
CREATE TABLE `log_punishments`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 768 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_punishments
-- ----------------------------

-- ----------------------------
-- Table structure for log_referrals
-- ----------------------------
DROP TABLE IF EXISTS `log_referrals`;
CREATE TABLE `log_referrals`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_referrals
-- ----------------------------

-- ----------------------------
-- Table structure for log_setstat
-- ----------------------------
DROP TABLE IF EXISTS `log_setstat`;
CREATE TABLE `log_setstat`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 29 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_setstat
-- ----------------------------
INSERT INTO `log_setstat` VALUES (23, '2021-06-24 15:53:07', 'Kiet_Le (uid: 35) set Kiet_Le\'s (uid: 35) gps to 1');
INSERT INTO `log_setstat` VALUES (24, '2022-04-18 14:02:37', 'Kiet_Le (uid: 36) set Kiet_Le\'s (uid: 36) hours to 5');
INSERT INTO `log_setstat` VALUES (25, '2022-04-18 14:14:44', 'Kiet_Le (uid: 36) set Kiet_Le\'s (uid: 36) wantedlevel to 1');
INSERT INTO `log_setstat` VALUES (26, '2022-04-18 14:14:47', 'Kiet_Le (uid: 36) set Kiet_Le\'s (uid: 36) wantedlevel to 5');
INSERT INTO `log_setstat` VALUES (27, '2022-04-18 14:14:49', 'Kiet_Le (uid: 36) set Kiet_Le\'s (uid: 36) wantedlevel to 4');
INSERT INTO `log_setstat` VALUES (28, '2022-04-18 14:18:36', 'Kiet_Le (uid: 36) set Kiet_Le\'s (uid: 36) wantedlevel to 0');

-- ----------------------------
-- Table structure for log_vip
-- ----------------------------
DROP TABLE IF EXISTS `log_vip`;
CREATE TABLE `log_vip`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `date` datetime NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 526 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of log_vip
-- ----------------------------

-- ----------------------------
-- Table structure for phonebook
-- ----------------------------
DROP TABLE IF EXISTS `phonebook`;
CREATE TABLE `phonebook`  (
  `name` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `number` int NULL DEFAULT NULL,
  UNIQUE INDEX `number`(`number` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of phonebook
-- ----------------------------

-- ----------------------------
-- Table structure for playerbackpack
-- ----------------------------
DROP TABLE IF EXISTS `playerbackpack`;
CREATE TABLE `playerbackpack`  (
  `ID` int NOT NULL,
  `BackpackOwner` int NOT NULL DEFAULT -1,
  `BackpackSize` int NOT NULL DEFAULT 0,
  `HouseStored` int NOT NULL DEFAULT 0,
  `VehicleStored` int NOT NULL DEFAULT 0,
  `Cash` int NOT NULL DEFAULT 0,
  `Crack` int NOT NULL DEFAULT 0,
  `Pot` int NOT NULL DEFAULT 0,
  `Mats` int NOT NULL DEFAULT 0,
  `Gun0` int NOT NULL DEFAULT 0,
  `Gun1` int NOT NULL DEFAULT 0,
  `Gun2` int NOT NULL DEFAULT 0,
  `Gun3` int NOT NULL DEFAULT 0,
  `Gun4` int NOT NULL DEFAULT 0
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of playerbackpack
-- ----------------------------

-- ----------------------------
-- Table structure for points
-- ----------------------------
DROP TABLE IF EXISTS `points`;
CREATE TABLE `points`  (
  `id` tinyint NULL DEFAULT NULL,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `capturedby` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'No-one',
  `capturedgang` tinyint NULL DEFAULT -1,
  `type` tinyint NULL DEFAULT 0,
  `profits` int NULL DEFAULT 0,
  `time` tinyint NULL DEFAULT 24,
  `point_x` float NULL DEFAULT 0,
  `point_y` float NULL DEFAULT 0,
  `point_z` float NULL DEFAULT 0,
  `pointinterior` tinyint NULL DEFAULT 0,
  `pointworld` int NULL DEFAULT 0
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of points
-- ----------------------------

-- ----------------------------
-- Table structure for posts_acp
-- ----------------------------
DROP TABLE IF EXISTS `posts_acp`;
CREATE TABLE `posts_acp`  (
  `title` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `date` date NOT NULL,
  `description` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `postedby` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of posts_acp
-- ----------------------------

-- ----------------------------
-- Table structure for shots
-- ----------------------------
DROP TABLE IF EXISTS `shots`;
CREATE TABLE `shots`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `playerid` smallint NULL DEFAULT NULL,
  `weaponid` tinyint NULL DEFAULT NULL,
  `hittype` tinyint NULL DEFAULT NULL,
  `hitid` int NULL DEFAULT NULL,
  `hitplayer` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `pos_x` float NULL DEFAULT NULL,
  `pos_y` float NULL DEFAULT NULL,
  `pos_z` float NULL DEFAULT NULL,
  `timestamp` int NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of shots
-- ----------------------------

-- ----------------------------
-- Table structure for speedcameras
-- ----------------------------
DROP TABLE IF EXISTS `speedcameras`;
CREATE TABLE `speedcameras`  (
  `speedID` int NOT NULL AUTO_INCREMENT,
  `speedRange` float NULL DEFAULT 0,
  `speedLimit` float NULL DEFAULT 0,
  `speedX` float NULL DEFAULT 0,
  `speedY` float NULL DEFAULT 0,
  `speedZ` float NULL DEFAULT 0,
  `speedAngle` float NULL DEFAULT 0,
  PRIMARY KEY (`speedID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 101 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of speedcameras
-- ----------------------------

-- ----------------------------
-- Table structure for spray_tags
-- ----------------------------
DROP TABLE IF EXISTS `spray_tags`;
CREATE TABLE `spray_tags`  (
  `id` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `owner` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT 'Ninguem',
  `text` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'Exemplo',
  `font` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'Arial',
  `fontsize` int NOT NULL DEFAULT 24,
  `bold` int NOT NULL DEFAULT 0,
  `color` int NOT NULL DEFAULT -1,
  `posx` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT '0.0',
  `posy` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT '0.0',
  `posz` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT '0.0',
  `posrx` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT '0.0',
  `posry` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT '0.0',
  `posrz` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `vw` int NULL DEFAULT 0,
  `interior` int NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of spray_tags
-- ----------------------------

-- ----------------------------
-- Table structure for texts
-- ----------------------------
DROP TABLE IF EXISTS `texts`;
CREATE TABLE `texts`  (
  `id` int NOT NULL,
  `sender_number` int NULL DEFAULT NULL,
  `recipient_number` int NULL DEFAULT NULL,
  `sender` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `date` datetime NULL DEFAULT NULL,
  `message` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of texts
-- ----------------------------

-- ----------------------------
-- Table structure for turfs
-- ----------------------------
DROP TABLE IF EXISTS `turfs`;
CREATE TABLE `turfs`  (
  `id` tinyint NULL DEFAULT NULL,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `capturedby` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'No-one',
  `capturedgang` tinyint NULL DEFAULT -1,
  `type` tinyint NULL DEFAULT 0,
  `time` tinyint NULL DEFAULT 12,
  `min_x` float NULL DEFAULT 0,
  `min_y` float NULL DEFAULT 0,
  `max_x` float NULL DEFAULT 0,
  `max_y` float NULL DEFAULT 0,
  `height` float NULL DEFAULT 0,
  UNIQUE INDEX `id`(`id` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of turfs
-- ----------------------------

-- ----------------------------
-- Table structure for users
-- ----------------------------
DROP TABLE IF EXISTS `users`;
CREATE TABLE `users`  (
  `notoriety` int NULL DEFAULT 0,
  `passwordchanged` tinyint(1) NOT NULL DEFAULT 0,
  `uid` int NOT NULL AUTO_INCREMENT,
  `username` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `password` varchar(129) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `regdate` datetime NULL DEFAULT NULL,
  `lastlogin` datetime NULL DEFAULT NULL,
  `ip` varchar(16) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `setup` tinyint(1) NULL DEFAULT 1,
  `gender` tinyint(1) NULL DEFAULT 1,
  `age` tinyint NULL DEFAULT 18,
  `skin` smallint NULL DEFAULT 299,
  `camera_x` float NULL DEFAULT 0,
  `camera_y` float NULL DEFAULT 0,
  `camera_z` float NULL DEFAULT 0,
  `pos_x` float NULL DEFAULT 0,
  `pos_y` float NULL DEFAULT 0,
  `pos_z` float NULL DEFAULT 0,
  `pos_a` float NULL DEFAULT 0,
  `interior` tinyint NULL DEFAULT 0,
  `hunger` int NULL DEFAULT 0,
  `thirsty` int NULL DEFAULT 0,
  `world` int NULL DEFAULT 0,
  `czid` int NULL DEFAULT 50000,
  `cash` int NULL DEFAULT 50000,
  `bank` int NULL DEFAULT 150000,
  `paycheck` int NULL DEFAULT 0,
  `level` int NULL DEFAULT 1,
  `exp` int NULL DEFAULT 0,
  `minutes` tinyint NULL DEFAULT 0,
  `hours` int NULL DEFAULT 2,
  `adminlevel` int NULL DEFAULT 0,
  `adminname` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'None',
  `helperlevel` tinyint NULL DEFAULT 0,
  `health` float NULL DEFAULT 100,
  `armor` float NULL DEFAULT 0,
  `upgradepoints` int NULL DEFAULT 0,
  `warnings` tinyint NULL DEFAULT 0,
  `injured` tinyint(1) NULL DEFAULT 0,
  `hospital` tinyint(1) NULL DEFAULT 0,
  `spawnhealth` float NULL DEFAULT 50,
  `spawnarmor` float NULL DEFAULT 0,
  `jailtype` tinyint(1) NULL DEFAULT 0,
  `jailtime` int NULL DEFAULT 0,
  `newbiemuted` tinyint(1) NULL DEFAULT 0,
  `helpmuted` tinyint(1) NULL DEFAULT 0,
  `admuted` tinyint(1) NULL DEFAULT 0,
  `livemuted` tinyint(1) NULL DEFAULT 0,
  `globalmuted` tinyint(1) NULL DEFAULT 0,
  `reportmuted` tinyint NULL DEFAULT 0,
  `reportwarns` tinyint NULL DEFAULT 0,
  `fightstyle` tinyint NULL DEFAULT 4,
  `locked` tinyint(1) NULL DEFAULT 0,
  `accent` varchar(16) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'None',
  `cookies` int NULL DEFAULT 0,
  `phone` int NULL DEFAULT 0,
  `job` int NULL DEFAULT -1,
  `secondjob` tinyint NULL DEFAULT -1,
  `crimes` int NULL DEFAULT 0,
  `arrested` int NULL DEFAULT 0,
  `wantedlevel` tinyint NULL DEFAULT 0,
  `materials` int NULL DEFAULT 2500,
  `weed` int NULL DEFAULT 0,
  `cocaine` int NULL DEFAULT 0,
  `meth` int NULL DEFAULT 0,
  `painkillers` int NULL DEFAULT 0,
  `seeds` int NULL DEFAULT 0,
  `ephedrine` int NULL DEFAULT 0,
  `muriaticacid` int NULL DEFAULT 0,
  `bakingsoda` int NULL DEFAULT 0,
  `cigars` int NULL DEFAULT 0,
  `walkietalkie` tinyint(1) NULL DEFAULT 0,
  `channel` int NULL DEFAULT 0,
  `rentinghouse` int NULL DEFAULT 0,
  `spraycans` int NULL DEFAULT 0,
  `boombox` tinyint(1) NULL DEFAULT 0,
  `mp3player` tinyint(1) NULL DEFAULT 0,
  `phonebook` tinyint(1) NULL DEFAULT 0,
  `fishingrod` tinyint(1) NULL DEFAULT 0,
  `fishingbait` int NULL DEFAULT 0,
  `fishweight` int NULL DEFAULT 0,
  `components` int NULL DEFAULT 0,
  `courierskill` int NULL DEFAULT 0,
  `fishingskill` int NULL DEFAULT 0,
  `guardskill` int NULL DEFAULT 0,
  `weaponskill` int NULL DEFAULT 0,
  `mechanicskill` int NULL DEFAULT 0,
  `lawyerskill` int NULL DEFAULT 0,
  `detectiveskill` int NULL DEFAULT 0,
  `smugglerskill` int NULL DEFAULT 0,
  `toggletextdraws` tinyint(1) NULL DEFAULT 0,
  `togglebug` tinyint(1) NULL DEFAULT 0,
  `toggleooc` tinyint(1) NULL DEFAULT 0,
  `togglephone` tinyint(1) NULL DEFAULT 0,
  `toggleadmin` tinyint(1) NULL DEFAULT 0,
  `togglehelper` tinyint(1) NULL DEFAULT 0,
  `togglenewbie` tinyint(1) NULL DEFAULT 0,
  `togglewt` tinyint(1) NULL DEFAULT 0,
  `toggleradio` tinyint(1) NULL DEFAULT 0,
  `togglevip` tinyint(1) NULL DEFAULT 0,
  `togglemusic` tinyint(1) NULL DEFAULT 0,
  `togglefaction` tinyint(1) NULL DEFAULT 0,
  `togglegang` tinyint(1) NULL DEFAULT 0,
  `togglenews` tinyint(1) NULL DEFAULT 0,
  `toggleglobal` tinyint(1) NULL DEFAULT 1,
  `togglecam` tinyint(1) NULL DEFAULT 0,
  `carlicense` tinyint(1) NULL DEFAULT 0,
  `vippackage` tinyint NULL DEFAULT 1,
  `viptime` int NULL DEFAULT 0,
  `vipcooldown` int NULL DEFAULT 0,
  `weapon_0` tinyint NULL DEFAULT 0,
  `weapon_1` tinyint NULL DEFAULT 0,
  `weapon_2` tinyint NULL DEFAULT 0,
  `weapon_3` tinyint NULL DEFAULT 0,
  `weapon_4` tinyint NULL DEFAULT 0,
  `weapon_5` tinyint NULL DEFAULT 0,
  `weapon_6` tinyint NULL DEFAULT 0,
  `weapon_7` tinyint NULL DEFAULT 0,
  `weapon_8` tinyint NULL DEFAULT 0,
  `weapon_9` tinyint NULL DEFAULT 0,
  `weapon_10` tinyint NULL DEFAULT 0,
  `weapon_11` tinyint NULL DEFAULT 0,
  `weapon_12` tinyint NULL DEFAULT 0,
  `ammo_0` smallint NULL DEFAULT 0,
  `ammo_1` smallint NULL DEFAULT 0,
  `ammo_2` smallint NULL DEFAULT 0,
  `ammo_3` smallint NULL DEFAULT 0,
  `ammo_4` smallint NULL DEFAULT 0,
  `ammo_5` smallint NULL DEFAULT 0,
  `ammo_6` smallint NULL DEFAULT 0,
  `ammo_7` smallint NULL DEFAULT 0,
  `ammo_8` smallint NULL DEFAULT 0,
  `ammo_9` smallint NULL DEFAULT 0,
  `ammo_10` smallint NULL DEFAULT 0,
  `ammo_11` smallint NULL DEFAULT 0,
  `ammo_12` smallint NULL DEFAULT 0,
  `faction` tinyint NULL DEFAULT -1,
  `factionid` int NULL DEFAULT -1,
  `gang` tinyint NULL DEFAULT -1,
  `factionrank` tinyint NULL DEFAULT 0,
  `gangrank` tinyint NULL DEFAULT 0,
  `division` tinyint NULL DEFAULT -1,
  `contracted` int NULL DEFAULT 0,
  `contractby` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'Nobody',
  `bombs` int NULL DEFAULT 0,
  `completedhits` int NULL DEFAULT 0,
  `failedhits` int NULL DEFAULT 0,
  `reports` int NULL DEFAULT 0,
  `helprequests` int NULL DEFAULT 0,
  `speedometer` tinyint(1) NULL DEFAULT 1,
  `factionmod` tinyint(1) NULL DEFAULT 0,
  `gangmod` tinyint(1) NULL DEFAULT 0,
  `banappealer` tinyint(1) NULL DEFAULT 0,
  `helpermanager` tinyint(1) NULL DEFAULT 0,
  `dynamicadmin` tinyint(1) NULL DEFAULT 0,
  `adminpersonnel` tinyint(1) NULL DEFAULT 0,
  `weedplanted` tinyint(1) NULL DEFAULT 0,
  `weedtime` int NULL DEFAULT 0,
  `weedgrams` int NULL DEFAULT 0,
  `weed_x` float NULL DEFAULT 0,
  `weed_y` float NULL DEFAULT 0,
  `weed_z` float NULL DEFAULT 0,
  `weed_a` float NULL DEFAULT 0,
  `inventoryupgrade` int NULL DEFAULT 0,
  `addictupgrade` int NULL DEFAULT 0,
  `traderupgrade` int NULL DEFAULT 0,
  `assetupgrade` int NULL DEFAULT 0,
  `pistolammo` smallint NULL DEFAULT 0,
  `shotgunammo` smallint NULL DEFAULT 0,
  `smgammo` smallint NULL DEFAULT 0,
  `arammo` smallint NULL DEFAULT 0,
  `rifleammo` smallint NULL DEFAULT 0,
  `hpammo` smallint NULL DEFAULT 0,
  `poisonammo` smallint NULL DEFAULT 0,
  `fmjammo` smallint NULL DEFAULT 0,
  `ammotype` tinyint NULL DEFAULT 0,
  `ammoweapon` tinyint NULL DEFAULT 0,
  `dmwarnings` tinyint NULL DEFAULT 0,
  `weaponrestricted` int NULL DEFAULT 0,
  `referral_uid` int NULL DEFAULT 0,
  `refercount` int NULL DEFAULT 0,
  `watch` tinyint(1) NULL DEFAULT 0,
  `gps` tinyint(1) NULL DEFAULT 0,
  `prisonedby` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'No-one',
  `prisonreason` varchar(128) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'None',
  `togglehud` tinyint(1) NULL DEFAULT 1,
  `clothes` smallint NULL DEFAULT -1,
  `showturfs` tinyint(1) NULL DEFAULT 0,
  `showlands` tinyint(1) NULL DEFAULT 0,
  `watchon` tinyint(1) NULL DEFAULT 0,
  `gpson` tinyint(1) NULL DEFAULT 0,
  `doublexp` int NULL DEFAULT 0,
  `couriercooldown` int NULL DEFAULT 0,
  `pizzacooldown` int NULL DEFAULT 0,
  `detectivecooldown` int NULL DEFAULT 0,
  `gascan` tinyint(1) NULL DEFAULT NULL,
  `duty` int NULL DEFAULT NULL,
  `bandana` tinyint NULL DEFAULT NULL,
  `login_date` date NULL DEFAULT NULL,
  `FormerAdmin` tinyint NOT NULL DEFAULT 0,
  `customtitle` varchar(128) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `customcolor` int NOT NULL DEFAULT -256,
  `scanneron` tinyint(1) NULL DEFAULT 0,
  `rimkits` int NULL DEFAULT 0,
  `bodykits` int NULL DEFAULT 0,
  `policescanner` tinyint(1) NULL DEFAULT 0,
  `firstaid` int NULL DEFAULT 0,
  `extraSongs` int NOT NULL DEFAULT 0,
  `top10` tinyint(1) NOT NULL DEFAULT 1,
  `totalfires` int NULL DEFAULT 0,
  `totalpatients` int NULL DEFAULT 0,
  `money_earned` bigint NULL DEFAULT 0,
  `money_spent` bigint NULL DEFAULT 0,
  `rope` int NULL DEFAULT 0,
  `blindfold` int NULL DEFAULT 0,
  `insurance` tinyint(1) NULL DEFAULT 0,
  `adminhide` tinyint(1) NULL DEFAULT 0,
  `passportphone` int NULL DEFAULT 0,
  `passportskin` smallint NULL DEFAULT 0,
  `passportlevel` int NULL DEFAULT 0,
  `passportname` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'None',
  `passport` tinyint(1) NULL DEFAULT 0,
  `globalmutetime` int NULL DEFAULT 0,
  `reportmutetime` int NULL DEFAULT 0,
  `newbiemutetime` int NULL DEFAULT 0,
  `togglereports` tinyint(1) NULL DEFAULT 0,
  `thiefcooldown` int NULL DEFAULT 0,
  `crackcooldown` int NULL DEFAULT 0,
  `laborupgrade` int NULL DEFAULT 0,
  `scripter` tinyint(1) NULL DEFAULT 0,
  `factionleader` tinyint(1) NULL DEFAULT 0,
  `thiefskill` int NULL DEFAULT 0,
  `togglewhisper` tinyint(1) NULL DEFAULT 0,
  `landkeys` tinyint NOT NULL DEFAULT -1,
  `rarecooldown` int NULL DEFAULT 0,
  `diamonds` smallint NULL DEFAULT 0,
  `bugged` tinyint(1) NULL DEFAULT 0,
  `gameaffairs` tinyint(1) NULL DEFAULT 0,
  `crew` tinyint NULL DEFAULT -1,
  `newbies` mediumint NULL DEFAULT 0,
  `rollerskates` tinyint NULL DEFAULT 0,
  `marriedto` int NULL DEFAULT -1,
  `humanresources` tinyint(1) NULL DEFAULT 0,
  `complaintmod` tinyint(1) NULL DEFAULT 0,
  `webdev` tinyint(1) NULL DEFAULT 0,
  `graphic` tinyint(1) NULL DEFAULT 0,
  `vehlock` tinyint(1) NULL DEFAULT 0,
  `togglepoint` tinyint(1) NULL DEFAULT 0,
  `gunlicense` tinyint(1) NULL DEFAULT 0,
  `togglevehicle` tinyint(1) NULL DEFAULT 0,
  `togglepm` tinyint(1) NULL DEFAULT 0,
  PRIMARY KEY (`uid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 38 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of users
-- ----------------------------
INSERT INTO `users` VALUES (0, 1, 36, 'Kiet_Le', 'D9C0314E8F49FC0088A31C88CA3F01AF9DB0209E72A1E7E4D155F82F8101BAA767C9E68B68F5CCA9A2DDD8F85EF1F52CB15ABA687CB0AA1C675F2D692DDDEFE5', NULL, '2022-04-18 14:18:16', '127.0.0.1', 0, 1, 30, 304, 1353.3, 244.208, 20.945, 1354.84, 242.57, 19.567, 251.016, 0, 84, 68, 0, 240698, 17675, 100, 0, 2, 0, 16, 5, 9, 'None', 0, 84.82, 0, 0, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 'None', 0, 394101, 1, -1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, -1, -1, 5, 0, -1, 0, 'Nobody', 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 'No-one', 'None', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, '', -256, 0, 0, 0, 0, 0, 0, 1, 0, 0, 20000, 2575, 0, 0, 0, 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `users` VALUES (0, 1, 37, 'Kiet_Lezz', 'D9C0314E8F49FC0088A31C88CA3F01AF9DB0209E72A1E7E4D155F82F8101BAA767C9E68B68F5CCA9A2DDD8F85EF1F52CB15ABA687CB0AA1C675F2D692DDDEFE5', NULL, '2022-04-18 14:03:58', '127.0.0.1', 0, 1, 30, 2, 1357.43, 245.416, 20.869, 1355.68, 242.666, 19.567, 147.51, 0, 90, 80, 0, 761523, 200, 100, 0, 1, 0, 10, 0, 0, 'None', 0, 20.14, 0, 0, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 'None', 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, 0, 0, -1, 0, 'Nobody', 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'No-one', 'None', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, '', -256, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- ----------------------------
-- Table structure for vehicles
-- ----------------------------
DROP TABLE IF EXISTS `vehicles`;
CREATE TABLE `vehicles`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `ownerid` int NULL DEFAULT 0,
  `owner` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'Nobody',
  `modelid` smallint NULL DEFAULT 0,
  `price` int NULL DEFAULT 0,
  `tickets` int NULL DEFAULT 0,
  `locked` tinyint(1) NULL DEFAULT 0,
  `plate` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'None',
  `fuel` tinyint NULL DEFAULT 100,
  `health` float NULL DEFAULT 1000,
  `pos_x` float NULL DEFAULT 0,
  `pos_y` float NULL DEFAULT 0,
  `pos_z` float NULL DEFAULT 0,
  `pos_a` float NULL DEFAULT 0,
  `color1` smallint NULL DEFAULT 0,
  `color2` smallint NULL DEFAULT 0,
  `paintjob` tinyint NULL DEFAULT -1,
  `interior` tinyint NULL DEFAULT 0,
  `world` int NULL DEFAULT 0,
  `neon` smallint NULL DEFAULT 0,
  `neonenabled` tinyint(1) NULL DEFAULT 0,
  `trunk` tinyint(1) NULL DEFAULT 0,
  `mod_1` smallint NULL DEFAULT 0,
  `mod_2` smallint NULL DEFAULT 0,
  `mod_3` smallint NULL DEFAULT 0,
  `mod_4` smallint NULL DEFAULT 0,
  `mod_5` smallint NULL DEFAULT 0,
  `mod_6` smallint NULL DEFAULT 0,
  `mod_7` smallint NULL DEFAULT 0,
  `mod_8` smallint NULL DEFAULT 0,
  `mod_9` smallint NULL DEFAULT 0,
  `mod_10` smallint NULL DEFAULT 0,
  `mod_11` smallint NULL DEFAULT 0,
  `mod_12` smallint NULL DEFAULT 0,
  `mod_13` smallint NULL DEFAULT 0,
  `mod_14` smallint NULL DEFAULT 0,
  `cash` int NULL DEFAULT 0,
  `materials` int NULL DEFAULT 0,
  `weed` int NULL DEFAULT 0,
  `cocaine` int NULL DEFAULT 0,
  `meth` int NULL DEFAULT 0,
  `painkillers` int NULL DEFAULT 0,
  `weapon_1` tinyint NULL DEFAULT 0,
  `weapon_2` tinyint NULL DEFAULT 0,
  `weapon_3` tinyint NULL DEFAULT 0,
  `ammo_1` smallint NULL DEFAULT 0,
  `ammo_2` smallint NULL DEFAULT 0,
  `ammo_3` smallint NULL DEFAULT 0,
  `gangid` tinyint NULL DEFAULT -1,
  `factiontype` tinyint NULL DEFAULT 0,
  `job` tinyint NULL DEFAULT -1,
  `respawndelay` int NULL DEFAULT 0,
  `pistolammo` smallint NULL DEFAULT 0,
  `shotgunammo` smallint NULL DEFAULT 0,
  `smgammo` smallint NULL DEFAULT 0,
  `arammo` smallint NULL DEFAULT 0,
  `rifleammo` smallint NULL DEFAULT 0,
  `hpammo` smallint NULL DEFAULT 0,
  `poisonammo` smallint NULL DEFAULT 0,
  `fmjammo` smallint NULL DEFAULT 0,
  `vippackage` tinyint NOT NULL DEFAULT 0,
  `alarm` tinyint NOT NULL DEFAULT 0,
  `weapon_4` tinyint NOT NULL DEFAULT 0,
  `weapon_5` tinyint NOT NULL DEFAULT 0,
  `siren` tinyint NULL DEFAULT 0,
  `rank` tinyint NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1040 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of vehicles
-- ----------------------------

-- ----------------------------
-- Table structure for weapons
-- ----------------------------
DROP TABLE IF EXISTS `weapons`;
CREATE TABLE `weapons`  (
  `uid` int NULL DEFAULT NULL,
  `slot` tinyint NULL DEFAULT NULL,
  `weaponid` tinyint NULL DEFAULT NULL,
  `ammo` smallint NULL DEFAULT NULL,
  UNIQUE INDEX `uid`(`uid` ASC, `slot` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of weapons
-- ----------------------------

SET FOREIGN_KEY_CHECKS = 1;

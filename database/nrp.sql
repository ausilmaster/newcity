-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Máy chủ: 127.0.0.1
-- Thời gian đã tạo: Th6 24, 2021 lúc 12:30 PM
-- Phiên bản máy phục vụ: 10.4.19-MariaDB
-- Phiên bản PHP: 8.0.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Cơ sở dữ liệu: `nrp`
--

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `achievements`
--

CREATE TABLE `achievements` (
  `uid` int(10) DEFAULT NULL,
  `achievement` varchar(32) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `actordb`
--

CREATE TABLE `actordb` (
  `ID` int(11) NOT NULL,
  `ActorName` text NOT NULL,
  `ActorVirtual` int(11) NOT NULL,
  `ActorX` float NOT NULL,
  `ActorA` float NOT NULL,
  `ActorY` float NOT NULL,
  `ActorZ` float NOT NULL,
  `Skin` int(11) NOT NULL,
  `AActive` int(11) NOT NULL,
  `Text` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `admins`
--

CREATE TABLE `admins` (
  `uid` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `aName` varchar(255) NOT NULL,
  `aLevel` int(11) NOT NULL,
  `totalReports` int(11) NOT NULL,
  `monthlyReports` int(11) NOT NULL,
  `weeklyReports` int(11) NOT NULL,
  `monthlyReset` int(11) NOT NULL,
  `weeklyReset` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `arrestpoints`
--

CREATE TABLE `arrestpoints` (
  `id` int(2) NOT NULL,
  `PosX` float(10,5) NOT NULL DEFAULT 0.00000,
  `PosY` float(10,5) NOT NULL DEFAULT 0.00000,
  `PosZ` float(10,5) NOT NULL DEFAULT 0.00000,
  `VW` int(5) NOT NULL DEFAULT 0,
  `Int` int(5) NOT NULL DEFAULT 0,
  `Type` int(1) NOT NULL DEFAULT 0,
  `jailVW` int(5) NOT NULL DEFAULT 0,
  `jailInt` int(5) NOT NULL DEFAULT 0,
  `jailpos1x` float(10,5) NOT NULL DEFAULT 0.00000,
  `jailpos1y` float(10,5) NOT NULL DEFAULT 0.00000,
  `jailpos1z` float(10,5) NOT NULL DEFAULT 0.00000,
  `jailpos2x` float(10,5) NOT NULL DEFAULT 0.00000,
  `jailpos2y` float(10,5) NOT NULL DEFAULT 0.00000,
  `jailpos2z` float(10,5) NOT NULL DEFAULT 0.00000
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `atms`
--

CREATE TABLE `atms` (
  `id` int(4) NOT NULL,
  `pos_x` float DEFAULT NULL,
  `pos_y` float DEFAULT NULL,
  `pos_z` float DEFAULT NULL,
  `pos_r` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `auctions`
--

CREATE TABLE `auctions` (
  `id` int(11) NOT NULL,
  `BiddingFor` varchar(64) NOT NULL DEFAULT '(none)',
  `InProgress` int(11) NOT NULL DEFAULT 0,
  `Bid` int(11) NOT NULL DEFAULT 0,
  `Bidder` int(11) NOT NULL DEFAULT 0,
  `Expires` int(11) NOT NULL DEFAULT 0,
  `Wining` varchar(24) NOT NULL DEFAULT '(none)',
  `Increment` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `backpack`
--

CREATE TABLE `backpack` (
  `pid` int(11) NOT NULL,
  `type` int(2) NOT NULL,
  `store1` int(2) DEFAULT NULL,
  `store2` int(2) DEFAULT NULL,
  `food` int(11) NOT NULL DEFAULT 0,
  `food2` int(11) NOT NULL DEFAULT 0,
  `mats` int(11) NOT NULL DEFAULT 0,
  `pot` int(5) DEFAULT 0,
  `crack` int(5) DEFAULT 0,
  `heroine` int(5) DEFAULT 0,
  `weap1` varchar(50) DEFAULT NULL,
  `weap2` varchar(50) DEFAULT NULL,
  `weap3` varchar(50) DEFAULT NULL,
  `weap4` varchar(50) DEFAULT NULL,
  `weap5` varchar(50) DEFAULT NULL,
  `Cash` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `bans`
--

CREATE TABLE `bans` (
  `id` int(10) NOT NULL,
  `username` varchar(24) DEFAULT NULL,
  `ip` varchar(16) DEFAULT NULL,
  `bannedby` varchar(24) DEFAULT NULL,
  `date` datetime DEFAULT NULL,
  `reason` varchar(128) DEFAULT NULL,
  `permanent` tinyint(1) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `businesses`
--

CREATE TABLE `businesses` (
  `id` int(10) NOT NULL,
  `ownerid` int(10) DEFAULT 0,
  `owner` varchar(24) DEFAULT 'Nobody',
  `type` tinyint(2) DEFAULT 0,
  `price` int(10) DEFAULT 0,
  `entryfee` int(10) DEFAULT 0,
  `locked` tinyint(1) DEFAULT 0,
  `timestamp` int(10) DEFAULT 0,
  `pos_x` float DEFAULT 0,
  `pos_y` float DEFAULT 0,
  `pos_z` float DEFAULT 0,
  `pos_a` float DEFAULT 0,
  `int_x` float DEFAULT 0,
  `int_y` float DEFAULT 0,
  `int_z` float DEFAULT 0,
  `int_a` float DEFAULT 0,
  `interior` tinyint(2) DEFAULT 0,
  `world` int(10) DEFAULT 0,
  `outsideint` tinyint(2) DEFAULT 0,
  `outsidevw` int(10) DEFAULT 0,
  `cash` int(10) DEFAULT 0,
  `products` int(10) DEFAULT 500,
  `name` varchar(64) NOT NULL DEFAULT 'Business Name',
  `message` varchar(128) NOT NULL DEFAULT 'Welcome use /buy to buy from this business',
  `color` int(10) DEFAULT -256,
  `freeze` tinyint(1) DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `businesses`
--

INSERT INTO `businesses` (`id`, `ownerid`, `owner`, `type`, `price`, `entryfee`, `locked`, `timestamp`, `pos_x`, `pos_y`, `pos_z`, `pos_a`, `int_x`, `int_y`, `int_z`, `int_a`, `interior`, `world`, `outsideint`, `outsidevw`, `cash`, `products`, `name`, `message`, `color`, `freeze`) VALUES
(416, 0, 'Nobody', 1, 800000, 0, 0, 0, 1368.06, -1279.84, 13.547, 92.514, 316.287, -169.647, 999.601, 0, 6, 3000416, 0, 0, 1500, 499, 'Business Name', 'Welcome use /buy to buy from this business', -256, 1),
(417, 0, 'Nobody', 0, 600000, 0, 0, 0, 1833.35, -1842.48, 13.578, 273.892, -27.438, -57.611, 1003.55, 0, 6, 3000417, 0, 0, 0, 500, 'Business Name', 'Welcome use /buy to buy from this business', -256, 1);

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `changes`
--

CREATE TABLE `changes` (
  `slot` tinyint(2) DEFAULT NULL,
  `text` varchar(64) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `charges`
--

CREATE TABLE `charges` (
  `id` int(10) NOT NULL,
  `uid` int(10) DEFAULT NULL,
  `chargedby` varchar(24) DEFAULT NULL,
  `date` datetime DEFAULT NULL,
  `reason` varchar(128) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `clothing`
--

CREATE TABLE `clothing` (
  `id` int(10) NOT NULL,
  `uid` int(10) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL,
  `modelid` smallint(5) DEFAULT NULL,
  `boneid` tinyint(2) DEFAULT NULL,
  `attached` tinyint(1) DEFAULT NULL,
  `pos_x` float DEFAULT NULL,
  `pos_y` float DEFAULT NULL,
  `pos_z` float DEFAULT NULL,
  `rot_x` float DEFAULT NULL,
  `rot_y` float DEFAULT NULL,
  `rot_z` float DEFAULT NULL,
  `scale_x` float DEFAULT NULL,
  `scale_y` float DEFAULT NULL,
  `scale_z` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `crates`
--

CREATE TABLE `crates` (
  `id` int(11) NOT NULL,
  `Active` int(11) NOT NULL DEFAULT 0,
  `CrateX` float NOT NULL DEFAULT 0,
  `CrateY` float NOT NULL DEFAULT 0,
  `CrateZ` float NOT NULL DEFAULT 0,
  `GunQuantity` int(11) NOT NULL DEFAULT 50,
  `InVehicle` int(11) NOT NULL DEFAULT 0,
  `Int` int(11) NOT NULL DEFAULT 0,
  `VW` int(11) NOT NULL DEFAULT 0,
  `PlacedBy` varchar(24) NOT NULL DEFAULT 'Unknown'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `crews`
--

CREATE TABLE `crews` (
  `id` tinyint(2) DEFAULT NULL,
  `crewid` tinyint(2) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `divisions`
--

CREATE TABLE `divisions` (
  `id` tinyint(2) DEFAULT NULL,
  `divisionid` tinyint(2) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `divisions`
--

INSERT INTO `divisions` (`id`, `divisionid`, `name`) VALUES
(0, 0, 'IA'),
(0, 1, 'TnR'),
(0, 2, 'HSIU'),
(0, 3, 'DET');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `entrances`
--

CREATE TABLE `entrances` (
  `id` int(10) NOT NULL,
  `ownerid` int(10) DEFAULT 0,
  `owner` varchar(24) DEFAULT NULL,
  `name` varchar(40) DEFAULT NULL,
  `iconid` smallint(5) DEFAULT 1239,
  `locked` tinyint(1) DEFAULT 0,
  `radius` float DEFAULT 3,
  `pos_x` float DEFAULT 0,
  `pos_y` float DEFAULT 0,
  `pos_z` float DEFAULT 0,
  `pos_a` float DEFAULT 0,
  `int_x` float DEFAULT 0,
  `int_y` float DEFAULT 0,
  `int_z` float DEFAULT 0,
  `int_a` float DEFAULT 0,
  `interior` tinyint(2) DEFAULT 0,
  `world` int(10) DEFAULT 0,
  `outsideint` tinyint(2) DEFAULT 0,
  `outsidevw` int(10) DEFAULT 0,
  `adminlevel` tinyint(2) DEFAULT 0,
  `factiontype` tinyint(2) DEFAULT 0,
  `vip` tinyint(2) DEFAULT 0,
  `vehicles` tinyint(1) DEFAULT 0,
  `freeze` tinyint(1) DEFAULT 1,
  `password` varchar(64) DEFAULT 'None',
  `label` tinyint(1) DEFAULT 1,
  `mapicon` tinyint(3) NOT NULL DEFAULT 0,
  `gang` tinyint(2) DEFAULT -1,
  `type` tinyint(2) DEFAULT 0,
  `color` int(10) DEFAULT -256
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `factionlockers`
--

CREATE TABLE `factionlockers` (
  `pos_x` float DEFAULT 0,
  `pos_y` float DEFAULT 0,
  `factionid` tinyint(2) DEFAULT NULL,
  `interior` tinyint(2) DEFAULT 0,
  `pos_z` float DEFAULT 0,
  `world` int(10) DEFAULT 0,
  `id` int(10) NOT NULL,
  `iconid` smallint(5) DEFAULT 1239,
  `label` tinyint(1) DEFAULT 1,
  `weapon_kevlar` tinyint(1) DEFAULT 1,
  `weapon_medkit` tinyint(1) DEFAULT 1,
  `weapon_nitestick` varchar(1) DEFAULT '0',
  `weapon_mace` tinyint(1) DEFAULT 0,
  `weapon_deagle` tinyint(1) DEFAULT 1,
  `weapon_shotgun` tinyint(1) DEFAULT 1,
  `weapon_mp5` tinyint(1) DEFAULT 1,
  `weapon_m4` tinyint(1) DEFAULT 1,
  `weapon_sniper` tinyint(1) DEFAULT 1,
  `weapon_spas12` tinyint(1) DEFAULT 1,
  `weapon_camera` tinyint(4) DEFAULT 0,
  `weapon_fire_extinguisher` tinyint(4) DEFAULT 0,
  `weapon_painkillers` tinyint(4) DEFAULT 0,
  `price_kevlar` smallint(5) DEFAULT 100,
  `price_medkit` smallint(5) DEFAULT 50,
  `price_nitestick` smallint(5) DEFAULT 0,
  `price_mace` smallint(5) DEFAULT 0,
  `price_deagle` smallint(5) DEFAULT 1000,
  `price_shotgun` smallint(5) DEFAULT 1000,
  `price_mp5` smallint(5) DEFAULT 2500,
  `price_m4` smallint(5) DEFAULT 3500,
  `price_sniper` smallint(5) DEFAULT 8500,
  `price_spas12` smallint(5) DEFAULT 7500,
  `price_camera` smallint(5) DEFAULT 100,
  `price_fire_extinguisher` smallint(5) DEFAULT 100,
  `price_painkillers` smallint(5) DEFAULT 100
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `factionpay`
--

CREATE TABLE `factionpay` (
  `id` tinyint(2) DEFAULT NULL,
  `rank` tinyint(2) DEFAULT NULL,
  `amount` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `factionpay`
--

INSERT INTO `factionpay` (`id`, `rank`, `amount`) VALUES
(0, 0, 100),
(0, 1, 250),
(0, 3, 550),
(0, 2, 450),
(0, 4, 600),
(0, 5, 650),
(0, 6, 700),
(0, 8, 950),
(0, 9, 1500);

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `factionranks`
--

CREATE TABLE `factionranks` (
  `id` tinyint(2) DEFAULT NULL,
  `rank` tinyint(2) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `factionranks`
--

INSERT INTO `factionranks` (`id`, `rank`, `name`) VALUES
(0, 1, 'Officer'),
(0, 0, 'Cadet'),
(0, 2, 'Senior Officer'),
(0, 3, 'Corporal'),
(0, 4, 'Sergeant'),
(0, 5, 'Staff Sergeant'),
(0, 6, 'Lieutenant'),
(0, 7, 'Captain'),
(0, 8, 'Deputy Chief'),
(0, 9, 'Chief Of Police'),
(1, 0, 'Trainee'),
(1, 1, 'Intermediate'),
(1, 2, 'Paramedic'),
(1, 3, 'Fire Protection'),
(1, 4, 'Lieutenant'),
(1, 5, 'Captain'),
(1, 6, 'Battalion Chief'),
(1, 7, 'Deputy Chief'),
(1, 8, 'Deputy Hospital'),
(1, 9, 'Chief Of Hospital');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `factions`
--

CREATE TABLE `factions` (
  `id` tinyint(2) DEFAULT NULL,
  `name` varchar(48) DEFAULT NULL,
  `leader` varchar(24) DEFAULT 'No-one',
  `type` tinyint(2) DEFAULT 0,
  `color` int(10) DEFAULT -1,
  `rankcount` tinyint(2) DEFAULT 6,
  `lockerx` float DEFAULT 0,
  `lockery` float DEFAULT 0,
  `lockerz` float DEFAULT 0,
  `lockerinterior` tinyint(2) DEFAULT 0,
  `lockerworld` int(10) DEFAULT 0,
  `turftokens` int(10) DEFAULT NULL,
  `shortname` varchar(64) DEFAULT NULL,
  `motd` varchar(128) DEFAULT NULL,
  `budget` int(8) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `factions`
--

INSERT INTO `factions` (`id`, `name`, `leader`, `type`, `color`, `rankcount`, `lockerx`, `lockery`, `lockerz`, `lockerinterior`, `lockerworld`, `turftokens`, `shortname`, `motd`, `budget`) VALUES
(0, 'Los Santos Police Department', 'No-one', 1, -1, 10, 0, 0, 0, 0, 0, NULL, 'LSPD', NULL, 0),
(1, 'Los Santos Fire/Medic Department', 'No-one', 2, -1, 10, 0, 0, 0, 0, 0, NULL, 'LSFMD', NULL, 0);

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `factionskins`
--

CREATE TABLE `factionskins` (
  `id` tinyint(2) DEFAULT NULL,
  `slot` tinyint(2) DEFAULT NULL,
  `skinid` smallint(3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `factionskins`
--

INSERT INTO `factionskins` (`id`, `slot`, `skinid`) VALUES
(1, 0, 274),
(1, 1, 275),
(1, 2, 276),
(1, 3, 277);

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `families`
--

CREATE TABLE `families` (
  `ID` int(4) NOT NULL,
  `Taken` int(11) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `MOTD` varchar(128) NOT NULL,
  `Leader` varchar(50) NOT NULL,
  `Bank` int(11) NOT NULL,
  `Cash` int(11) NOT NULL,
  `USafe` int(11) NOT NULL,
  `SafeX` float NOT NULL,
  `SafeY` float NOT NULL,
  `SafeZ` float NOT NULL,
  `Pot` int(11) NOT NULL,
  `Crack` int(11) NOT NULL,
  `Mats` int(11) NOT NULL,
  `Rank1` varchar(50) NOT NULL,
  `Rank2` varchar(50) NOT NULL,
  `Rank3` varchar(50) NOT NULL,
  `Rank4` varchar(50) NOT NULL,
  `Rank5` varchar(50) NOT NULL,
  `Rank6` varchar(50) NOT NULL,
  `Members` int(11) NOT NULL,
  `MaxSkins` int(11) NOT NULL,
  `Skins0` int(11) NOT NULL,
  `Skins1` int(11) NOT NULL,
  `Skins2` int(11) NOT NULL,
  `Skins3` int(11) NOT NULL,
  `Skins4` int(11) NOT NULL,
  `Skins5` int(11) NOT NULL,
  `Skins6` int(11) NOT NULL,
  `Skins7` int(11) NOT NULL,
  `Color` int(11) NOT NULL,
  `TurfTokens` int(11) NOT NULL,
  `Guns0` int(11) NOT NULL,
  `Guns1` int(11) NOT NULL,
  `Guns2` int(11) NOT NULL,
  `Guns3` int(11) NOT NULL,
  `Guns4` int(11) NOT NULL,
  `Guns5` int(11) NOT NULL,
  `Guns6` int(11) NOT NULL,
  `Guns7` int(11) NOT NULL,
  `Guns8` int(11) NOT NULL,
  `Guns9` int(11) NOT NULL,
  `Heroin` int(11) NOT NULL,
  `GunAmmo0` int(11) NOT NULL,
  `GunAmmo1` int(11) NOT NULL,
  `GunAmmo2` int(11) NOT NULL,
  `GunAmmo3` int(11) NOT NULL,
  `GunAmmo4` int(11) NOT NULL,
  `GunAmmo5` int(11) NOT NULL,
  `GunAmmo6` int(11) NOT NULL,
  `GunAmmo7` int(11) NOT NULL,
  `GunAmmo8` int(11) NOT NULL,
  `GunAmmo9` int(11) NOT NULL,
  `Meth` int(11) NOT NULL,
  `Seeds` int(11) NOT NULL,
  `Opium` int(11) NOT NULL,
  `Acid` int(11) NOT NULL,
  `CrackStuff` int(11) NOT NULL,
  `Rank0` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `flags`
--

CREATE TABLE `flags` (
  `id` int(10) NOT NULL,
  `uid` int(10) DEFAULT NULL,
  `flaggedby` varchar(24) DEFAULT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(128) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `furniture`
--

CREATE TABLE `furniture` (
  `id` int(10) NOT NULL,
  `houseid` int(10) DEFAULT NULL,
  `modelid` smallint(5) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL,
  `price` int(10) DEFAULT NULL,
  `pos_x` float DEFAULT NULL,
  `pos_y` float DEFAULT NULL,
  `pos_z` float DEFAULT NULL,
  `rot_x` float DEFAULT NULL,
  `rot_y` float DEFAULT NULL,
  `rot_z` float DEFAULT NULL,
  `interior` tinyint(2) DEFAULT NULL,
  `world` int(10) DEFAULT NULL,
  `door_opened` tinyint(1) DEFAULT 0,
  `door_locked` tinyint(1) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `gangranks`
--

CREATE TABLE `gangranks` (
  `id` tinyint(2) DEFAULT NULL,
  `rank` tinyint(2) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `gangs`
--

CREATE TABLE `gangs` (
  `id` tinyint(2) DEFAULT NULL,
  `name` varchar(32) DEFAULT 'None',
  `motd` varchar(128) DEFAULT 'None',
  `leader` varchar(24) DEFAULT 'No-one',
  `color` int(10) DEFAULT -256,
  `strikes` tinyint(1) DEFAULT 0,
  `level` tinyint(2) DEFAULT 1,
  `points` int(10) DEFAULT 0,
  `turftokens` int(10) DEFAULT 0,
  `stash_x` float DEFAULT 0,
  `stash_y` float DEFAULT 0,
  `stash_z` float DEFAULT 0,
  `stashinterior` tinyint(2) DEFAULT 0,
  `stashworld` int(10) DEFAULT 0,
  `cash` int(10) DEFAULT 0,
  `materials` int(10) DEFAULT 0,
  `weed` int(10) DEFAULT 0,
  `cocaine` int(10) DEFAULT 0,
  `meth` int(10) DEFAULT 0,
  `painkillers` int(10) DEFAULT 0,
  `pistolammo` int(10) DEFAULT 0,
  `shotgunammo` int(10) DEFAULT 0,
  `smgammo` int(10) DEFAULT 0,
  `arammo` int(10) DEFAULT 0,
  `rifleammo` int(10) DEFAULT 0,
  `hpammo` int(10) DEFAULT 0,
  `poisonammo` int(10) DEFAULT 0,
  `fmjammo` int(10) DEFAULT 0,
  `weapon_9mm` int(10) DEFAULT 0,
  `weapon_sdpistol` int(10) DEFAULT 0,
  `weapon_deagle` int(10) DEFAULT 0,
  `weapon_shotgun` int(10) DEFAULT 0,
  `weapon_spas12` int(10) DEFAULT 0,
  `weapon_sawnoff` int(10) DEFAULT 0,
  `weapon_tec9` int(10) DEFAULT 0,
  `weapon_uzi` int(10) DEFAULT 0,
  `weapon_mp5` int(10) DEFAULT 0,
  `weapon_ak47` int(10) DEFAULT 0,
  `weapon_m4` int(10) DEFAULT 0,
  `weapon_rifle` int(10) DEFAULT 0,
  `weapon_sniper` int(10) DEFAULT 0,
  `weapon_molotov` int(10) DEFAULT 0,
  `armsdealer` tinyint(1) DEFAULT 0,
  `drugdealer` tinyint(1) DEFAULT 0,
  `arms_x` float DEFAULT 0,
  `arms_y` float DEFAULT 0,
  `arms_z` float DEFAULT 0,
  `arms_a` float DEFAULT 0,
  `drug_x` float DEFAULT 0,
  `drug_y` float DEFAULT 0,
  `drug_z` float DEFAULT 0,
  `drug_a` float DEFAULT 0,
  `armsworld` int(10) DEFAULT 0,
  `drugworld` int(10) DEFAULT 0,
  `drugweed` int(10) DEFAULT 0,
  `drugcocaine` int(10) DEFAULT 0,
  `drugmeth` int(10) DEFAULT 0,
  `armsmaterials` int(10) DEFAULT 0,
  `armsprice_1` int(10) DEFAULT 0,
  `armsprice_2` int(10) DEFAULT 0,
  `armsprice_3` int(10) DEFAULT 0,
  `armsprice_4` int(10) DEFAULT 0,
  `armsprice_5` int(10) DEFAULT 0,
  `armsprice_6` int(10) DEFAULT 0,
  `armsprice_7` int(10) DEFAULT 0,
  `armsprice_8` int(10) DEFAULT 0,
  `armsprice_9` int(10) NOT NULL DEFAULT 0,
  `armsprice_10` int(10) NOT NULL DEFAULT 0,
  `armsprice_11` int(10) NOT NULL DEFAULT 0,
  `armsprice_12` tinyint(2) NOT NULL DEFAULT 0,
  `weed_price` int(10) DEFAULT 0,
  `cocaine_price` int(10) DEFAULT 0,
  `meth_price` int(10) DEFAULT 0,
  `matlevel` tinyint(3) NOT NULL DEFAULT 0,
  `gunlevel` tinyint(3) NOT NULL DEFAULT 0,
  `alliance` tinyint(4) NOT NULL DEFAULT -1,
  `rivals` tinyint(4) DEFAULT -1,
  `war1` tinyint(2) NOT NULL DEFAULT 0,
  `war2` tinyint(2) NOT NULL DEFAULT 0,
  `war3` tinyint(2) NOT NULL DEFAULT 0,
  `rank_9mm` tinyint(2) NOT NULL DEFAULT 1,
  `rank_sdpistol` tinyint(2) NOT NULL DEFAULT 1,
  `rank_deagle` tinyint(2) NOT NULL DEFAULT 2,
  `rank_shotgun` tinyint(2) NOT NULL DEFAULT 1,
  `rank_spas12` tinyint(2) NOT NULL DEFAULT 4,
  `rank_sawnoff` tinyint(2) NOT NULL DEFAULT 4,
  `rank_tec9` tinyint(2) NOT NULL DEFAULT 1,
  `rank_uzi` tinyint(2) NOT NULL DEFAULT 1,
  `rank_mp5` tinyint(2) NOT NULL DEFAULT 2,
  `rank_ak47` tinyint(2) NOT NULL DEFAULT 3,
  `rank_m4` tinyint(2) NOT NULL DEFAULT 4,
  `rank_rifle` tinyint(2) NOT NULL DEFAULT 2,
  `rank_sniper` tinyint(2) NOT NULL DEFAULT 5,
  `rank_molotov` tinyint(2) NOT NULL DEFAULT 5,
  `rank_vest` tinyint(2) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `gangskins`
--

CREATE TABLE `gangskins` (
  `id` tinyint(2) DEFAULT NULL,
  `slot` tinyint(2) DEFAULT NULL,
  `skinid` smallint(3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `gangtags`
--

CREATE TABLE `gangtags` (
  `gangid` int(11) NOT NULL,
  `text` text NOT NULL,
  `fontid` int(11) NOT NULL,
  `pname` text NOT NULL,
  `color` int(11) NOT NULL,
  `x` float(11,4) NOT NULL DEFAULT 0.0000,
  `y` float(11,4) NOT NULL DEFAULT 0.0000,
  `z` float(11,4) NOT NULL DEFAULT 0.0000,
  `rx` float(11,4) NOT NULL DEFAULT 0.0000,
  `ry` float(11,4) NOT NULL DEFAULT 0.0000,
  `rz` float(11,4) NOT NULL DEFAULT 0.0000,
  `ID` int(11) NOT NULL,
  `pdbid` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `garages`
--

CREATE TABLE `garages` (
  `id` int(10) NOT NULL,
  `ownerid` int(10) DEFAULT 0,
  `owner` varchar(24) DEFAULT NULL,
  `type` tinyint(1) DEFAULT 0,
  `price` int(10) DEFAULT 0,
  `locked` tinyint(1) DEFAULT 0,
  `timestamp` int(10) DEFAULT 0,
  `pos_x` float DEFAULT 0,
  `pos_y` float DEFAULT 0,
  `pos_z` float DEFAULT 0,
  `pos_a` float DEFAULT 0,
  `exit_x` float DEFAULT 0,
  `exit_y` float DEFAULT 0,
  `exit_z` float DEFAULT 0,
  `exit_a` float DEFAULT 0,
  `world` int(10) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `gates`
--

CREATE TABLE `gates` (
  `ID` int(11) NOT NULL,
  `HID` int(11) NOT NULL DEFAULT -1,
  `Speed` float NOT NULL DEFAULT 10,
  `Range` float NOT NULL DEFAULT 10,
  `Model` int(11) NOT NULL DEFAULT 18631,
  `VW` int(11) NOT NULL DEFAULT 0,
  `Int` int(11) NOT NULL DEFAULT 0,
  `Pass` varchar(24) NOT NULL DEFAULT '',
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
  `Allegiance` int(11) NOT NULL DEFAULT 0,
  `GroupType` int(11) NOT NULL DEFAULT 0,
  `GroupID` int(2) NOT NULL DEFAULT -1,
  `GangID` int(2) NOT NULL DEFAULT -1,
  `RenderHQ` int(11) NOT NULL DEFAULT 1,
  `Timer` int(1) NOT NULL DEFAULT 0,
  `Automate` int(11) NOT NULL,
  `Locked` int(11) NOT NULL,
  `TIndex` int(11) NOT NULL,
  `TModel` int(11) NOT NULL,
  `TColor` int(11) NOT NULL,
  `Facility` int(11) NOT NULL,
  `TTXD` varchar(32) NOT NULL,
  `TTexture` varchar(42) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `graffiti`
--

CREATE TABLE `graffiti` (
  `graffitiText` varchar(40) CHARACTER SET latin1 COLLATE latin1_danish_ci DEFAULT NULL,
  `graffitiID` int(10) NOT NULL,
  `graffitiX` float DEFAULT 0,
  `graffitiY` float DEFAULT 0,
  `graffitiZ` float DEFAULT 0,
  `graffitiAngle` int(11) DEFAULT 0,
  `graffitiColor` int(11) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `gunracks`
--

CREATE TABLE `gunracks` (
  `rackID` int(12) NOT NULL,
  `rackHouse` int(12) DEFAULT 0,
  `rackX` float DEFAULT 0,
  `rackY` float DEFAULT 0,
  `rackZ` float DEFAULT 0,
  `rackA` float DEFAULT 0,
  `rackInterior` int(12) DEFAULT 0,
  `rackWorld` int(12) DEFAULT 0,
  `rackWeapon1` int(12) DEFAULT 0,
  `rackAmmo1` int(12) DEFAULT 0,
  `rackWeapon2` int(12) DEFAULT 0,
  `rackAmmo2` int(12) DEFAULT 0,
  `rackWeapon3` int(12) DEFAULT 0,
  `rackAmmo3` int(12) DEFAULT 0,
  `rackWeapon4` int(12) DEFAULT 0,
  `rackAmmo4` int(12) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `houses`
--

CREATE TABLE `houses` (
  `id` int(10) NOT NULL,
  `ownerid` int(10) DEFAULT 0,
  `owner` varchar(24) DEFAULT 'Nobody',
  `type` tinyint(2) DEFAULT 0,
  `price` int(10) DEFAULT 0,
  `rentprice` int(10) DEFAULT 0,
  `level` tinyint(2) DEFAULT 0,
  `locked` tinyint(1) DEFAULT 0,
  `timestamp` int(10) DEFAULT 0,
  `pos_x` float DEFAULT 0,
  `pos_y` float DEFAULT 0,
  `pos_z` float DEFAULT 0,
  `pos_a` float DEFAULT 0,
  `int_x` float DEFAULT 0,
  `int_y` float DEFAULT 0,
  `int_z` float DEFAULT 0,
  `int_a` float DEFAULT 0,
  `interior` tinyint(2) DEFAULT 0,
  `world` int(10) DEFAULT 0,
  `outsideint` int(10) DEFAULT 0,
  `outsidevw` int(10) DEFAULT 0,
  `cash` int(10) DEFAULT 0,
  `materials` int(10) DEFAULT 0,
  `weed` int(10) DEFAULT 0,
  `cocaine` int(10) DEFAULT 0,
  `meth` int(10) DEFAULT 0,
  `painkillers` int(10) DEFAULT 0,
  `weapon_1` tinyint(2) DEFAULT 0,
  `weapon_2` tinyint(2) DEFAULT 0,
  `weapon_3` tinyint(2) DEFAULT 0,
  `weapon_4` tinyint(2) DEFAULT 0,
  `weapon_5` tinyint(2) DEFAULT 0,
  `weapon_6` tinyint(2) DEFAULT 0,
  `weapon_7` tinyint(2) DEFAULT 0,
  `weapon_8` tinyint(2) DEFAULT 0,
  `weapon_9` tinyint(2) DEFAULT 0,
  `weapon_10` tinyint(2) DEFAULT 0,
  `ammo_1` smallint(5) DEFAULT 0,
  `ammo_2` smallint(5) DEFAULT 0,
  `ammo_3` smallint(5) DEFAULT 0,
  `ammo_4` smallint(5) DEFAULT 0,
  `ammo_5` smallint(5) DEFAULT 0,
  `ammo_6` tinyint(2) DEFAULT 0,
  `ammo_7` tinyint(2) DEFAULT 0,
  `ammo_8` tinyint(2) DEFAULT 0,
  `ammo_9` tinyint(2) DEFAULT 0,
  `ammo_10` tinyint(2) DEFAULT 0,
  `pistolammo` smallint(5) DEFAULT 0,
  `shotgunammo` smallint(5) DEFAULT 0,
  `smgammo` smallint(5) DEFAULT 0,
  `arammo` smallint(5) DEFAULT 0,
  `rifleammo` smallint(5) DEFAULT 0,
  `hpammo` smallint(5) DEFAULT 0,
  `poisonammo` smallint(5) DEFAULT 0,
  `fmjammo` smallint(5) DEFAULT 0,
  `delivery` tinyint(2) DEFAULT 1,
  `lights` tinyint(1) DEFAULT 1,
  `freeze` tinyint(1) DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `houses`
--

INSERT INTO `houses` (`id`, `ownerid`, `owner`, `type`, `price`, `rentprice`, `level`, `locked`, `timestamp`, `pos_x`, `pos_y`, `pos_z`, `pos_a`, `int_x`, `int_y`, `int_z`, `int_a`, `interior`, `world`, `outsideint`, `outsidevw`, `cash`, `materials`, `weed`, `cocaine`, `meth`, `painkillers`, `weapon_1`, `weapon_2`, `weapon_3`, `weapon_4`, `weapon_5`, `weapon_6`, `weapon_7`, `weapon_8`, `weapon_9`, `weapon_10`, `ammo_1`, `ammo_2`, `ammo_3`, `ammo_4`, `ammo_5`, `ammo_6`, `ammo_7`, `ammo_8`, `ammo_9`, `ammo_10`, `pistolammo`, `shotgunammo`, `smgammo`, `arammo`, `rifleammo`, `hpammo`, `poisonammo`, `fmjammo`, `delivery`, `lights`, `freeze`) VALUES
(105, 0, 'Nobody', 1, 50000, 0, 0, 0, 0, 2067.45, -1731.51, 13.876, 87.606, 1434.08, -1832.79, 1313.56, 270, 2, 1000105, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1);

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `kills`
--

CREATE TABLE `kills` (
  `id` int(10) NOT NULL,
  `killer_uid` int(10) DEFAULT NULL,
  `target_uid` int(10) DEFAULT NULL,
  `killer` varchar(24) DEFAULT NULL,
  `target` varchar(24) DEFAULT NULL,
  `reason` varchar(24) DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `landobjects`
--

CREATE TABLE `landobjects` (
  `id` int(10) NOT NULL,
  `landid` int(10) DEFAULT NULL,
  `modelid` smallint(5) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL,
  `price` int(10) DEFAULT NULL,
  `pos_x` float DEFAULT NULL,
  `pos_y` float DEFAULT NULL,
  `pos_z` float DEFAULT NULL,
  `rot_x` float DEFAULT NULL,
  `rot_y` float DEFAULT NULL,
  `rot_z` float DEFAULT NULL,
  `door_opened` tinyint(1) DEFAULT 0,
  `door_locked` tinyint(1) DEFAULT 0,
  `move_x` float DEFAULT 0,
  `move_y` float DEFAULT 0,
  `move_z` float DEFAULT 0,
  `move_rx` float DEFAULT 0,
  `move_ry` float DEFAULT 0,
  `move_rz` float DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `lands`
--

CREATE TABLE `lands` (
  `id` int(10) NOT NULL,
  `ownerid` int(10) DEFAULT 0,
  `owner` varchar(24) DEFAULT 'Nobody',
  `price` int(10) DEFAULT 0,
  `min_x` float DEFAULT 0,
  `min_y` float DEFAULT 0,
  `max_x` float DEFAULT 0,
  `max_y` float DEFAULT 0,
  `height` float DEFAULT 0,
  `ltext_x` float DEFAULT 0,
  `ltext_y` float DEFAULT 0,
  `ltext_z` float DEFAULT 0,
  `level` tinyint(2) DEFAULT 0,
  `factiontype` tinyint(2) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `locations`
--

CREATE TABLE `locations` (
  `id` int(4) NOT NULL,
  `name` varchar(64) NOT NULL,
  `pos_x` float NOT NULL,
  `pos_y` float NOT NULL,
  `pos_z` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_admin`
--

CREATE TABLE `log_admin` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `log_admin`
--

INSERT INTO `log_admin` (`id`, `date`, `description`) VALUES
(6109, '2021-06-24 15:44:24', 'Kiet_Le (uid: 35) has made Kiet_Le (uid: 35) a dynamic admin.'),
(6110, '2021-06-24 17:06:44', 'Kiet_Le (uid: 35) has made Kiet_Le (uid: 35) a faction moderator.');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_bans`
--

CREATE TABLE `log_bans` (
  `id` int(10) NOT NULL,
  `uid` int(10) DEFAULT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_cheat`
--

CREATE TABLE `log_cheat` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `log_cheat`
--

INSERT INTO `log_cheat` (`id`, `date`, `description`) VALUES
(70, '2017-07-10 02:49:32', 'Ronald_Eastwood (uid: 634) possibly hacked armor. (old: 0.00, new: 100.00)'),
(71, '2017-07-10 02:55:32', 'Ronald_Eastwood (uid: 634) had a desynced Desert Eagle with 170 ammunition.'),
(72, '2017-07-11 07:12:41', 'Jenice_Salvatore (uid: 632) possibly hacked armor. (old: 0.00, new: 100.00)'),
(73, '2017-07-12 00:49:03', 'Borgy_Salvatore (uid: 631) possibly hacked armor. (old: 0.00, new: 100.00)'),
(74, '2017-07-12 01:18:46', 'Xac_Uley (uid: 667) possibly speedhacked, speed: 360.8 km/h'),
(75, '2017-07-12 01:18:47', 'Xac_Uley (uid: 667) possibly speedhacked, speed: 350.2 km/h'),
(76, '2017-07-12 04:24:29', 'Borgy_salvatore (uid: 631) possibly hacked armor. (old: 0.00, new: 100.00)'),
(77, '2017-07-12 04:24:43', 'Daniel_Villanueva (uid: 648) possibly hacked armor. (old: 0.00, new: 100.00)'),
(78, '2017-07-12 05:17:48', 'Justine_Salvatore (uid: 649) possibly hacked armor. (old: 0.00, new: 100.00)'),
(79, '2017-07-12 10:16:39', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 64.00, new: 100.00)'),
(80, '2017-07-12 10:17:10', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 64.00, new: 100.00)'),
(81, '2017-07-12 10:21:47', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 0.00, new: 64.00)'),
(82, '2017-07-12 10:21:47', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 73.00)'),
(83, '2017-07-12 10:22:00', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 73.00, new: 100.00)'),
(84, '2017-07-12 10:23:37', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 64.00, new: 100.00)'),
(85, '2017-07-12 10:24:27', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 53.00)'),
(86, '2017-07-12 10:24:28', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 64.00, new: 100.00)'),
(87, '2017-07-12 10:29:28', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 0.00, new: 64.00)'),
(88, '2017-07-12 10:29:39', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)'),
(89, '2017-07-12 10:29:39', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 64.00, new: 100.00)'),
(90, '2017-07-12 11:36:29', 'Aziz_Hfaidh (uid: 662) possibly hacked armor. (old: 0.00, new: 100.00)'),
(91, '2017-07-13 02:51:53', 'Jason_Wox (uid: 675) possibly hacked armor. (old: 0.00, new: 100.00)'),
(92, '2017-07-13 06:58:19', 'James_Garcia (uid: 676) had a desynced Desert Eagle with 131 ammunition.'),
(93, '2017-07-13 07:52:46', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)'),
(94, '2017-07-13 07:52:47', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 59.00, new: 100.00)'),
(95, '2017-07-13 07:57:47', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 0.00, new: 59.00)'),
(96, '2017-07-13 07:58:04', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)'),
(97, '2017-07-13 07:58:07', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 59.00, new: 100.00)'),
(98, '2017-07-13 08:03:16', 'Dwayne_Diaz (uid: 672) possibly hacked armor. (old: 0.00, new: 59.00)'),
(99, '2017-07-13 08:09:54', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)'),
(100, '2017-07-13 08:13:42', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)'),
(101, '2017-07-13 08:17:24', 'Jhon_Diaz (uid: 664) possibly hacked armor. (old: 0.00, new: 100.00)'),
(102, '2017-07-14 03:38:39', 'Chris_Pine (uid: 681) had a desynced Desert Eagle with 114 ammunition.'),
(103, '2017-07-14 03:38:39', 'Chris_Pine (uid: 681) had a desynced Desert Eagle with 114 ammunition.'),
(104, '2017-07-14 03:38:40', 'Chris_Pine (uid: 681) had a desynced Desert Eagle with 114 ammunition.'),
(105, '2017-07-14 03:38:59', 'Chris_Pine (uid: 681) had a desynced Desert Eagle with 114 ammunition.'),
(106, '2017-07-14 08:22:15', 'Fares_snoop (uid: 687) possibly speedhacked, speed: 362.3 km/h'),
(107, '2017-07-14 08:22:16', 'Fares_snoop (uid: 687) possibly speedhacked, speed: 361.9 km/h'),
(108, '2017-07-14 08:22:17', 'Fares_snoop (uid: 687) possibly speedhacked, speed: 362.1 km/h'),
(109, '2017-07-14 08:22:18', 'Fares_snoop (uid: 687) possibly speedhacked, speed: 362.1 km/h'),
(110, '2017-07-14 22:40:03', 'Asykon_Wolf (uid: 699) possibly speedhacked, speed: 361.5 km/h'),
(111, '2017-07-14 22:40:04', 'Asykon_Wolf (uid: 699) possibly speedhacked, speed: 361.6 km/h'),
(112, '2017-07-14 22:40:07', 'Asykon_Wolf (uid: 699) possibly speedhacked, speed: 361.7 km/h'),
(113, '2017-07-14 22:40:08', 'Asykon_Wolf (uid: 699) possibly speedhacked, speed: 361.6 km/h'),
(114, '2017-07-15 00:56:48', 'Vincent_Shock (uid: 707) possibly hacked armor. (old: 0.00, new: 100.00)'),
(115, '2018-04-03 14:12:22', 'Lan_Smoke (uid: 789) possibly hacked armor. (old: 0.00, new: 100.00)'),
(116, '2018-04-03 14:14:56', 'Poseidon_Vincre (uid: 808) possibly hacked armor. (old: 0.00, new: 100.00)'),
(117, '2018-04-03 14:14:56', 'Lan_Smoke (uid: 789) possibly hacked armor. (old: 0.00, new: 100.00)'),
(118, '2018-04-03 14:14:56', 'Clark_savage (uid: 729) possibly hacked armor. (old: 0.00, new: 50.00)'),
(119, '2018-04-03 14:18:30', 'Poseidon_Vincre (uid: 808) possibly hacked armor. (old: 0.00, new: 100.00)'),
(120, '2018-04-03 14:20:29', 'Lan_Smoke (uid: 789) possibly hacked armor. (old: 0.00, new: 100.00)'),
(121, '2018-09-25 14:33:47', 'Franco_V_Shadow (uid: 822) possibly hacked armor. (old: 0.00, new: 100.00)'),
(122, '2018-09-26 11:55:52', 'dean_parker (uid: 846) possibly speedhacked, speed: 350.1 km/h'),
(123, '2018-09-26 11:55:54', 'dean_parker (uid: 846) possibly speedhacked, speed: 378.7 km/h'),
(124, '2018-09-26 11:55:55', 'dean_parker (uid: 846) possibly speedhacked, speed: 399.9 km/h'),
(125, '2018-09-26 11:55:56', 'dean_parker (uid: 846) possibly speedhacked, speed: 415.7 km/h'),
(126, '2018-09-26 12:56:44', 'John_Bud (uid: 844) possibly hacked armor. (old: 0.00, new: 100.00)'),
(127, '2018-09-26 13:06:37', 'Jax_Ortega (uid: 831) possibly hacked armor. (old: 0.00, new: 1.00)'),
(128, '2018-09-26 13:07:28', 'Jax_Ortega (uid: 831) possibly hacked armor. (old: 0.00, new: 7.00)'),
(129, '2018-09-26 17:56:20', 'Cv_Jeremy (uid: 851) possibly hacked armor. (old: 0.00, new: 100.00)'),
(130, '2018-09-27 08:56:49', 'kervin_pogi (uid: 847) possibly hacked armor. (old: 0.00, new: 100.00)'),
(131, '2018-09-27 09:33:59', 'Klos_B_Varios (uid: 853) possibly hacked armor. (old: 58.00, new: 100.00)'),
(132, '2018-09-28 06:05:01', 'Yuri_V_Gwapigs (uid: 863) had a desynced Desert Eagle with 19942 ammunition.'),
(133, '2018-09-28 13:48:41', 'Klos_B_Varios (uid: 853) possibly hacked armor. (old: 0.00, new: 100.00)'),
(134, '2018-09-28 18:05:29', 'Cv_jeremiah (uid: 851) possibly hacked armor. (old: 47.00, new: 168.00)'),
(135, '2018-09-29 05:55:52', 'Adolf_Jones (uid: 892) possibly hacked armor. (old: 183.00, new: 208.00)'),
(136, '2018-09-29 06:00:14', 'joseff_ocampo (uid: 890) possibly hacked armor. (old: 25.00, new: 207.00)'),
(137, '2018-09-29 06:05:08', 'Adolf_Jones (uid: 892) possibly hacked armor. (old: 23.00, new: 238.00)'),
(138, '2018-09-30 03:45:24', 'Jack_Park (uid: 873) possibly hacked armor. (old: 0.00, new: 100.00)'),
(139, '2018-09-30 04:15:37', 'Alvina_Love (uid: 907) possibly hacked armor. (old: 0.00, new: 100.00)'),
(140, '2018-09-30 08:02:48', 'John_Fabian (uid: 916) possibly hacked armor. (old: 0.00, new: 100.00)'),
(141, '2018-09-30 08:48:37', 'Yuri_V_Bud (uid: 863) had a desynced Desert Eagle with 19991 ammunition.'),
(142, '2018-09-30 09:03:02', 'Ken_Chan (uid: 867) possibly hacked armor. (old: 0.00, new: 100.00)'),
(143, '2018-09-30 11:54:10', 'joseph_jumadas (uid: 929) possibly hacked armor. (old: 0.00, new: 100.00)'),
(144, '2018-09-30 13:23:31', 'Lucid_Dreams (uid: 894) possibly hacked armor. (old: 7.00, new: 100.00)'),
(145, '2018-09-30 13:39:13', 'Drake_Freeman (uid: 937) had a desynced Desert Eagle with 19994 ammunition.'),
(146, '2018-09-30 16:28:13', 'Daniel_Sultan (uid: 928) possibly hacked armor. (old: 0.00, new: 100.00)'),
(147, '2018-10-01 04:29:58', 'richard_dreams (uid: 930) possibly hacked armor. (old: 0.00, new: 53.00)'),
(148, '2018-10-01 07:26:35', 'Dante_Ruiz (uid: 956) had a desynced Combat Shotgun with 145 ammunition.'),
(149, '2018-10-01 07:26:35', 'Dante_Ruiz (uid: 956) had a desynced Nite Stick with 170 ammunition.'),
(150, '2018-10-01 07:26:36', 'Dante_Ruiz (uid: 956) had a desynced Combat Shotgun with 145 ammunition.'),
(151, '2018-10-01 07:34:47', 'Dante_Ruiz (uid: 956) possibly speedhacked, speed: 359.5 km/h'),
(152, '2018-10-01 07:45:31', 'Jeff_Walker (uid: 949) possibly hacked armor. (old: 0.00, new: 100.00)'),
(153, '2018-10-01 07:54:30', 'van_wise (uid: 958) possibly hacked armor. (old: 0.00, new: 100.00)'),
(154, '2018-10-01 12:52:33', 'Alex_Freeman (uid: 967) had a desynced Pool Cue with 48 ammunition.'),
(155, '2018-10-01 12:53:14', 'Alex_Freeman (uid: 967) had a desynced Pool Cue with 48 ammunition.'),
(156, '2018-10-01 12:53:20', 'Alex_Freeman (uid: 967) had a desynced Pool Cue with 48 ammunition.'),
(157, '2018-10-01 12:53:21', 'Alex_Freeman (uid: 967) had a desynced Pool Cue with 48 ammunition.'),
(158, '2018-10-01 14:07:58', 'Lucid_Dreams (uid: 945) possibly hacked armor. (old: 98.00, new: 100.00)'),
(159, '2018-10-02 03:59:34', 'Daniel_Dreams (uid: 928) possibly hacked armor. (old: 0.00, new: 100.00)'),
(160, '2018-10-02 04:03:09', 'Lian_Dreams (uid: 931) possibly hacked armor. (old: 0.00, new: 20.00)'),
(161, '2018-10-02 04:44:24', 'Sophia_Bud (uid: 881) possibly hacked armor. (old: 0.00, new: 100.00)'),
(162, '2018-10-02 05:20:55', 'John_Dreams (uid: 916) possibly hacked armor. (old: 0.00, new: 100.00)'),
(163, '2018-10-02 06:26:40', 'kevin_k_banks (uid: 910) possibly hacked armor. (old: 0.00, new: 100.00)'),
(164, '2018-10-02 11:06:00', 'Elijah_Montefalco (uid: 964) possibly hacked armor. (old: 0.00, new: 3.00)'),
(165, '2018-10-03 04:43:05', 'Lian_Dreams (uid: 931) possibly speedhacked, speed: 361.7 km/h'),
(166, '2018-10-03 04:43:06', 'Lian_Dreams (uid: 931) possibly speedhacked, speed: 361.7 km/h'),
(167, '2018-10-03 09:03:04', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)'),
(168, '2018-10-03 09:12:17', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)'),
(169, '2018-10-03 09:15:49', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)'),
(170, '2018-10-03 09:17:22', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 60.00, new: 100.00)'),
(171, '2018-10-03 09:17:35', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 53.00, new: 100.00)'),
(172, '2018-10-03 09:20:59', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)'),
(173, '2018-10-03 09:54:35', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)'),
(174, '2018-10-03 10:03:55', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)'),
(175, '2018-10-03 10:19:59', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)'),
(176, '2018-10-03 10:33:09', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)'),
(177, '2018-10-03 10:37:04', 'kiven_Gamble (uid: 991) possibly hacked armor. (old: 0.00, new: 100.00)'),
(178, '2018-10-03 12:38:49', 'Lrizz_Devil (uid: 903) possibly hacked armor. (old: 0.00, new: 7.00)'),
(179, '2018-10-04 06:58:31', 'Ken_Dreams (uid: 996) possibly speedhacked, speed: 362.2 km/h'),
(180, '2018-10-04 10:27:54', 'Ken_Dreams (uid: 996) possibly hacked armor. (old: 7.00, new: 100.00)'),
(181, '2018-10-05 02:20:59', 'Ken_Dreams (uid: 996) possibly speedhacked, speed: 360.7 km/h'),
(182, '2018-10-05 02:28:44', 'Dave_Dreams (uid: 935) possibly hacked armor. (old: 0.00, new: 100.00)'),
(183, '2018-10-05 02:30:25', 'Dave_Dreams (uid: 935) possibly hacked armor. (old: 53.00, new: 100.00)'),
(184, '2018-10-05 02:33:37', 'Ken_Dreams (uid: 996) possibly speedhacked, speed: 361.4 km/h'),
(185, '2018-10-05 02:58:11', 'Dave_Dreams (uid: 935) possibly hacked armor. (old: 51.00, new: 100.00)'),
(186, '2018-10-21 02:45:16', 'Trisha_Maxine (uid: 1041) possibly hacked armor. (old: 0.00, new: 100.00)'),
(187, '2018-10-21 06:24:02', 'Jeff_Walker (uid: 1047) possibly hacked armor. (old: 0.00, new: 100.00)'),
(188, '2018-10-25 14:42:24', 'Chuck_Taylor (uid: 1090) had a desynced UZI with 19998 ammunition.'),
(189, '2018-10-25 14:49:07', 'Chuck_Taylor (uid: 1090) had a desynced M4 with 19999 ammunition.'),
(190, '2018-10-25 15:26:17', 'Perfecto_Slash (uid: 1098) possibly hacked armor. (old: 0.00, new: 100.00)'),
(191, '2018-10-26 01:43:22', 'Daniel_Corman (uid: 1075) possibly hacked armor. (old: 0.00, new: 100.00)'),
(192, '2018-10-26 04:30:52', 'Ashley_Zhin (uid: 1117) possibly hacked armor. (old: 0.00, new: 97.00)'),
(193, '2018-10-26 05:21:38', 'Sophia_Rolex (uid: 1125) possibly hacked armor. (old: 0.00, new: 100.00)'),
(194, '2018-10-26 06:51:47', 'Jhon_Carter (uid: 1126) possibly hacked armor. (old: 0.00, new: 100.00)'),
(195, '2018-10-26 10:58:10', 'Leonidas_Savage (uid: 1146) possibly hacked armor. (old: 0.00, new: 100.00)'),
(196, '2018-10-26 11:18:20', 'mustafa_abir (uid: 1127) possibly hacked armor. (old: 0.00, new: 90.00)'),
(197, '2018-10-26 13:49:35', 'Clark_Chives (uid: 1143) possibly hacked armor. (old: 0.00, new: 100.00)'),
(198, '2018-10-26 14:23:30', 'Prince_Fabian (uid: 1084) had a desynced Desert Eagle with 19999 ammunition.'),
(199, '2018-10-26 14:31:17', 'Max_S_Schneider (uid: 1153) possibly hacked armor. (old: 0.00, new: 100.00)'),
(200, '2018-10-26 14:42:10', 'Troi_Miller (uid: 1167) possibly hacked armor. (old: 0.00, new: 100.00)'),
(201, '2018-10-27 03:58:31', 'Mea_Black (uid: 1070) possibly hacked armor. (old: 0.00, new: 100.00)'),
(202, '2018-10-27 17:26:20', 'Pritz_G_Ramirez (uid: 1081) possibly hacked armor. (old: 0.00, new: 100.00)'),
(203, '2018-10-28 06:17:07', 'Kentoy_Vincre (uid: 1195) possibly hacked armor. (old: 0.00, new: 100.00)'),
(204, '2018-10-28 06:25:50', 'Pritz_G_Ramirez (uid: 1081) possibly hacked armor. (old: 0.00, new: 95.00)'),
(205, '2018-10-28 06:36:34', 'Kore_G_Ramirez (uid: 1192) possibly hacked armor. (old: 0.00, new: 50.00)'),
(206, '2018-10-28 09:40:04', 'Timmy_Powell (uid: 1115) possibly hacked armor. (old: 0.00, new: 100.00)'),
(207, '2018-10-28 10:16:33', 'Justin_Jhay (uid: 1068) possibly speedhacked, speed: 362.5 km/h'),
(208, '2018-10-28 10:16:34', 'Justin_Jhay (uid: 1068) possibly speedhacked, speed: 362.5 km/h'),
(209, '2018-10-28 10:16:35', 'Justin_Jhay (uid: 1068) possibly speedhacked, speed: 362.5 km/h'),
(210, '2018-10-28 10:16:54', 'Justin_Jhay (uid: 1068) possibly speedhacked, speed: 359.6 km/h'),
(211, '2018-10-28 13:13:22', 'john_richard_don (uid: 1213) possibly hacked armor. (old: 92.00, new: 100.00)'),
(212, '2018-10-28 13:17:34', 'Pritz_G_Ramirez (uid: 1081) possibly hacked armor. (old: 0.00, new: 100.00)'),
(213, '2018-10-29 01:42:14', 'Eurie_G_Ramirez (uid: 1198) possibly hacked armor. (old: 0.00, new: 100.00)'),
(214, '2018-10-29 04:17:11', 'Daffa_Adaki (uid: 1222) possibly hacked armor. (old: 0.00, new: 100.00)'),
(215, '2018-10-29 11:48:34', 'Prince_Wise (uid: 1129) possibly hacked armor. (old: 25.00, new: 100.00)'),
(216, '2018-10-30 02:17:51', 'Lenard_Lean (uid: 1231) possibly hacked armor. (old: 0.00, new: 100.00)'),
(217, '2018-10-30 03:51:14', 'Smith_Johnson (uid: 1233) possibly hacked armor. (old: 0.00, new: 100.00)'),
(218, '2018-10-30 04:35:43', 'Jack_Dein (uid: 1236) possibly hacked armor. (old: 0.00, new: 100.00)'),
(219, '2018-10-30 05:04:07', 'Steve_Jobs (uid: 1073) possibly hacked armor. (old: 7.00, new: 100.00)'),
(220, '2018-10-30 05:07:20', 'Steve_Jobs (uid: 1073) possibly hacked armor. (old: 0.00, new: 100.00)'),
(221, '2018-10-30 05:08:36', 'Steve_Jobs (uid: 1073) possibly hacked armor. (old: 0.00, new: 100.00)'),
(222, '2018-10-30 05:25:11', 'prince_wise (uid: 1129) had a desynced Sniper Rifle with 19999 ammunition.'),
(223, '2018-10-30 05:32:45', 'prince_wise (uid: 1129) possibly hacked armor. (old: 0.00, new: 90.00)'),
(224, '2018-10-30 11:22:33', 'Conner_Lacroix (uid: 1079) possibly hacked armor. (old: 0.00, new: 100.00)'),
(225, '2018-10-30 11:22:33', 'Ocir_Lacroix (uid: 1212) possibly hacked armor. (old: 0.00, new: 100.00)'),
(226, '2018-10-30 11:27:42', 'Conner_Lacroix (uid: 1079) possibly hacked armor. (old: 0.00, new: 100.00)'),
(227, '2018-10-30 11:35:08', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 53.00)'),
(228, '2018-10-30 11:42:54', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 100.00)'),
(229, '2018-10-30 11:49:41', 'Conner_Lacroix (uid: 1079) possibly hacked armor. (old: 0.00, new: 100.00)'),
(230, '2018-10-30 12:31:48', 'Lorence_X_Marks (uid: 1232) possibly hacked armor. (old: 2.00, new: 100.00)'),
(231, '2018-10-30 14:18:01', 'lance_v_shadow (uid: 1211) possibly hacked armor. (old: 0.00, new: 7.00)'),
(232, '2018-10-31 03:53:25', 'Genz_T_Slice (uid: 1085) possibly hacked armor. (old: 0.00, new: 100.00)'),
(233, '2018-10-31 05:07:49', 'Rhods_Fabian (uid: 1067) possibly hacked armor. (old: 0.00, new: 100.00)'),
(234, '2018-10-31 05:13:48', 'Rhods_Fabian (uid: 1067) possibly hacked armor. (old: 0.00, new: 80.00)'),
(235, '2018-10-31 07:10:20', 'Adrian_Pascual (uid: 1270) possibly hacked armor. (old: 0.00, new: 100.00)'),
(236, '2018-10-31 07:10:31', 'Adrian_Pascual (uid: 1270) had a desynced Baseball Bat with 174 ammunition.'),
(237, '2018-10-31 07:10:32', 'Adrian_Pascual (uid: 1270) had a desynced Baseball Bat with 174 ammunition.'),
(238, '2018-10-31 07:57:24', 'Genz_T_Slice (uid: 1085) possibly hacked armor. (old: 0.00, new: 100.00)'),
(239, '2018-10-31 08:10:19', 'Drizz_Powell (uid: 1273) had a desynced Fire Extinguisher with 19999 ammunition.'),
(240, '2018-10-31 08:19:35', 'Christo_Valentino (uid: 1275) possibly hacked armor. (old: 30.00, new: 100.00)'),
(241, '2018-10-31 09:27:10', 'Seteven_William (uid: 1274) had a desynced Sawn-off Shotgun with 19999 ammunition.'),
(242, '2018-10-31 10:48:08', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 22.00)'),
(243, '2018-10-31 10:48:08', 'Genz_T_Slice (uid: 1085) possibly hacked armor. (old: 0.00, new: 100.00)'),
(244, '2018-10-31 10:48:08', 'Daniel_Corman (uid: 1075) possibly hacked armor. (old: 0.00, new: 75.00)'),
(245, '2018-10-31 10:52:12', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 22.00)'),
(246, '2018-10-31 12:37:17', 'Zac_G_Hiest (uid: 1103) possibly hacked armor. (old: 0.00, new: 100.00)'),
(247, '2018-10-31 14:23:20', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 12.00)'),
(248, '2018-10-31 14:23:27', 'James_Foxton (uid: 1140) possibly hacked armor. (old: 0.00, new: 100.00)'),
(249, '2018-11-01 03:23:25', 'Sophia_Rolex (uid: 1125) had a desynced Sniper Rifle with 19999 ammunition.'),
(250, '2018-11-01 03:23:35', 'Kai_Slash (uid: 1297) possibly hacked armor. (old: 14.00, new: 100.00)'),
(251, '2018-11-01 04:02:32', 'Christopher_S_Zhin (uid: 1298) possibly hacked armor. (old: 0.00, new: 100.00)'),
(252, '2018-11-01 05:11:34', 'Kyle_Wazowski (uid: 1303) possibly hacked armor. (old: 0.00, new: 30.00)'),
(253, '2018-11-01 06:01:26', 'Christo_Valentino (uid: 1275) possibly hacked armor. (old: 98.00, new: 100.00)'),
(254, '2018-11-01 06:15:58', 'Rara_William (uid: 1281) possibly hacked armor. (old: 7.00, new: 100.00)'),
(255, '2018-11-01 06:17:57', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 75.00, new: 100.00)'),
(256, '2018-11-01 06:20:21', 'Lucky_One (uid: 1208) possibly hacked armor. (old: 0.00, new: 100.00)'),
(257, '2018-11-01 07:39:38', 'Rara_William (uid: 1281) possibly hacked armor. (old: 0.00, new: 98.00)'),
(258, '2018-11-01 09:16:41', 'Lely_Maddox (uid: 1316) possibly hacked armor. (old: 0.00, new: 100.00)'),
(259, '2018-11-01 09:47:17', 'Kai_Fabians (uid: 1297) possibly speedhacked, speed: 362.2 km/h'),
(260, '2018-11-01 09:48:07', 'Kai_Fabians (uid: 1297) possibly speedhacked, speed: 361.1 km/h'),
(261, '2018-11-01 09:48:08', 'Kai_Fabians (uid: 1297) possibly speedhacked, speed: 361.2 km/h'),
(262, '2018-11-01 09:48:09', 'Kai_Fabians (uid: 1297) possibly speedhacked, speed: 361.2 km/h'),
(263, '2018-11-01 10:06:00', 'Kyle_Fabian (uid: 1303) possibly hacked armor. (old: 0.00, new: 97.00)'),
(264, '2018-11-01 10:09:30', 'Dixus_William (uid: 1282) possibly hacked armor. (old: 0.00, new: 95.00)'),
(265, '2018-11-01 10:12:48', 'James_Foxton (uid: 1140) possibly hacked armor. (old: 0.00, new: 100.00)'),
(266, '2018-11-01 10:23:46', 'Rell_Corman (uid: 1078) possibly hacked armor. (old: 0.00, new: 80.00)'),
(267, '2018-11-01 10:35:11', 'Rara_Mutiara (uid: 1281) possibly hacked armor. (old: 0.00, new: 58.00)'),
(268, '2018-11-01 11:17:46', 'Kyle_Fabian (uid: 1303) possibly hacked armor. (old: 0.00, new: 100.00)'),
(269, '2019-06-03 04:16:53', 'Albert_G_Street (uid: 1363) possibly hacked armor. (old: 0.00, new: 100.00)'),
(270, '2019-06-03 04:58:55', 'Jaim_Desanta (uid: 1330) possibly hacked armor. (old: 0.00, new: 100.00)'),
(271, '2019-06-03 05:18:57', 'Jaim_Desanta (uid: 1330) possibly hacked armor. (old: 0.00, new: 100.00)'),
(272, '2019-06-04 05:15:25', 'John_Turner (uid: 1347) possibly hacked armor. (old: 0.00, new: 58.00)'),
(273, '2019-06-04 20:37:20', 'Hizashi_Nagato (uid: 1376) possibly hacked armor. (old: 0.00, new: 100.00)'),
(274, '2019-06-05 11:42:45', 'Rodel_Nacianceno (uid: 8) possibly teleport hacked (distance: 130.3)'),
(275, '2019-06-05 11:53:55', 'Shane_Amphibia (uid: 6) possibly teleport hacked (distance: 180.1)'),
(276, '2019-06-05 11:56:14', 'Rodel_Nacianceno (uid: 8) possibly teleport hacked (distance: 181.4)'),
(277, '2019-06-05 12:21:22', 'Rodel_Nacianceno (uid: 8) possibly teleport hacked (distance: 181.9)'),
(278, '2019-06-05 18:34:43', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 116.1)'),
(279, '2019-06-05 18:34:47', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 119.5)'),
(280, '2019-06-05 18:34:50', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 113.7)'),
(281, '2019-06-05 18:34:54', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 114.8)'),
(282, '2019-06-05 18:34:58', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 114.2)'),
(283, '2019-06-05 19:07:43', 'Hizashi_Nagato (uid: 17) possibly teleport hacked (distance: 116.6)'),
(284, '2019-06-06 09:02:29', 'Palawars_Akmel (uid: 20) possibly teleport hacked (distance: 424.9)'),
(285, '2019-06-06 09:02:40', 'Palawars_Akmel (uid: 20) possibly teleport hacked (distance: 278.3)'),
(286, '2019-06-06 09:02:55', 'Palawars_Akmel (uid: 20) possibly teleport hacked (distance: 124.5)'),
(287, '2019-06-06 10:21:58', 'Jake_Smoke (uid: 21) possibly teleport hacked (distance: 115.9)'),
(288, '2019-06-09 04:38:22', 'Ashley_Kuznetsova (uid: 33) possibly teleport hacked (distance: 123.5)');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_contracts`
--

CREATE TABLE `log_contracts` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_cp`
--

CREATE TABLE `log_cp` (
  `id` int(11) NOT NULL,
  `executer` text DEFAULT NULL,
  `description` text DEFAULT NULL,
  `date` timestamp NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_dicebet`
--

CREATE TABLE `log_dicebet` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_faction`
--

CREATE TABLE `log_faction` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_gang`
--

CREATE TABLE `log_gang` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_give`
--

CREATE TABLE `log_give` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_givecookie`
--

CREATE TABLE `log_givecookie` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_givegun`
--

CREATE TABLE `log_givegun` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_givemoney`
--

CREATE TABLE `log_givemoney` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_makeadmin`
--

CREATE TABLE `log_makeadmin` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `log_makeadmin`
--

INSERT INTO `log_makeadmin` (`id`, `date`, `description`) VALUES
(26, '2021-06-24 15:43:52', 'Kiet_Le (uid: 35) set Kiet_Le\'s (uid: 35) admin level to 9');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_makehelper`
--

CREATE TABLE `log_makehelper` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_namechanges`
--

CREATE TABLE `log_namechanges` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_namehistory`
--

CREATE TABLE `log_namehistory` (
  `id` int(10) NOT NULL,
  `uid` int(10) DEFAULT NULL,
  `oldname` varchar(24) DEFAULT NULL,
  `newname` varchar(24) DEFAULT NULL,
  `changedby` varchar(24) DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_property`
--

CREATE TABLE `log_property` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_punishments`
--

CREATE TABLE `log_punishments` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_referrals`
--

CREATE TABLE `log_referrals` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_setstat`
--

CREATE TABLE `log_setstat` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `log_setstat`
--

INSERT INTO `log_setstat` (`id`, `date`, `description`) VALUES
(23, '2021-06-24 15:53:07', 'Kiet_Le (uid: 35) set Kiet_Le\'s (uid: 35) gps to 1');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `log_vip`
--

CREATE TABLE `log_vip` (
  `id` int(10) NOT NULL,
  `date` datetime DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `phonebook`
--

CREATE TABLE `phonebook` (
  `name` varchar(24) DEFAULT NULL,
  `number` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `phonebook`
--

INSERT INTO `phonebook` (`name`, `number`) VALUES
('Lui_Mendez', 5);

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `playerbackpack`
--

CREATE TABLE `playerbackpack` (
  `ID` int(11) NOT NULL,
  `BackpackOwner` int(11) NOT NULL DEFAULT -1,
  `BackpackSize` int(11) NOT NULL DEFAULT 0,
  `HouseStored` int(11) NOT NULL DEFAULT 0,
  `VehicleStored` int(11) NOT NULL DEFAULT 0,
  `Cash` int(11) NOT NULL DEFAULT 0,
  `Crack` int(11) NOT NULL DEFAULT 0,
  `Pot` int(11) NOT NULL DEFAULT 0,
  `Mats` int(11) NOT NULL DEFAULT 0,
  `Gun0` int(11) NOT NULL DEFAULT 0,
  `Gun1` int(11) NOT NULL DEFAULT 0,
  `Gun2` int(11) NOT NULL DEFAULT 0,
  `Gun3` int(11) NOT NULL DEFAULT 0,
  `Gun4` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `points`
--

CREATE TABLE `points` (
  `id` tinyint(2) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL,
  `capturedby` varchar(24) DEFAULT 'No-one',
  `capturedgang` tinyint(2) DEFAULT -1,
  `type` tinyint(2) DEFAULT 0,
  `profits` int(10) DEFAULT 0,
  `time` tinyint(2) DEFAULT 24,
  `point_x` float DEFAULT 0,
  `point_y` float DEFAULT 0,
  `point_z` float DEFAULT 0,
  `pointinterior` tinyint(2) DEFAULT 0,
  `pointworld` int(10) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `posts_acp`
--

CREATE TABLE `posts_acp` (
  `title` varchar(64) NOT NULL,
  `date` date NOT NULL,
  `description` text NOT NULL,
  `postedby` varchar(24) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `shots`
--

CREATE TABLE `shots` (
  `id` int(10) NOT NULL,
  `playerid` smallint(3) DEFAULT NULL,
  `weaponid` tinyint(2) DEFAULT NULL,
  `hittype` tinyint(2) DEFAULT NULL,
  `hitid` int(10) DEFAULT NULL,
  `hitplayer` varchar(24) DEFAULT NULL,
  `pos_x` float DEFAULT NULL,
  `pos_y` float DEFAULT NULL,
  `pos_z` float DEFAULT NULL,
  `timestamp` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `speedcameras`
--

CREATE TABLE `speedcameras` (
  `speedID` int(12) NOT NULL,
  `speedRange` float DEFAULT 0,
  `speedLimit` float DEFAULT 0,
  `speedX` float DEFAULT 0,
  `speedY` float DEFAULT 0,
  `speedZ` float DEFAULT 0,
  `speedAngle` float DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `spray_tags`
--

CREATE TABLE `spray_tags` (
  `id` int(11) UNSIGNED NOT NULL,
  `owner` varchar(32) CHARACTER SET utf8 NOT NULL DEFAULT 'Ninguem',
  `text` varchar(32) NOT NULL DEFAULT 'Exemplo',
  `font` varchar(32) NOT NULL DEFAULT 'Arial',
  `fontsize` int(11) NOT NULL DEFAULT 24,
  `bold` int(11) NOT NULL DEFAULT 0,
  `color` int(11) NOT NULL DEFAULT -1,
  `posx` varchar(32) DEFAULT '0.0',
  `posy` varchar(32) DEFAULT '0.0',
  `posz` varchar(32) DEFAULT '0.0',
  `posrx` varchar(32) DEFAULT '0.0',
  `posry` varchar(32) DEFAULT '0.0',
  `posrz` varchar(32) DEFAULT NULL,
  `vw` int(11) DEFAULT 0,
  `interior` int(11) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `texts`
--

CREATE TABLE `texts` (
  `id` int(10) NOT NULL,
  `sender_number` int(10) DEFAULT NULL,
  `recipient_number` int(10) DEFAULT NULL,
  `sender` varchar(24) DEFAULT NULL,
  `date` datetime DEFAULT NULL,
  `message` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `turfs`
--

CREATE TABLE `turfs` (
  `id` tinyint(2) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL,
  `capturedby` varchar(24) DEFAULT 'No-one',
  `capturedgang` tinyint(2) DEFAULT -1,
  `type` tinyint(2) DEFAULT 0,
  `time` tinyint(2) DEFAULT 12,
  `min_x` float DEFAULT 0,
  `min_y` float DEFAULT 0,
  `max_x` float DEFAULT 0,
  `max_y` float DEFAULT 0,
  `height` float DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `users`
--

CREATE TABLE `users` (
  `notoriety` int(10) DEFAULT 0,
  `passwordchanged` tinyint(1) NOT NULL DEFAULT 0,
  `uid` int(10) NOT NULL,
  `username` varchar(24) DEFAULT NULL,
  `password` varchar(129) DEFAULT NULL,
  `regdate` datetime DEFAULT NULL,
  `lastlogin` datetime DEFAULT NULL,
  `ip` varchar(16) DEFAULT NULL,
  `setup` tinyint(1) DEFAULT 1,
  `gender` tinyint(1) DEFAULT 1,
  `age` tinyint(3) DEFAULT 18,
  `skin` smallint(3) DEFAULT 299,
  `camera_x` float DEFAULT 0,
  `camera_y` float DEFAULT 0,
  `camera_z` float DEFAULT 0,
  `pos_x` float DEFAULT 0,
  `pos_y` float DEFAULT 0,
  `pos_z` float DEFAULT 0,
  `pos_a` float DEFAULT 0,
  `interior` tinyint(2) DEFAULT 0,
  `world` int(10) DEFAULT 0,
  `cash` int(10) DEFAULT 50000,
  `bank` int(10) DEFAULT 150000,
  `paycheck` int(10) DEFAULT 0,
  `level` int(10) DEFAULT 1,
  `exp` int(10) DEFAULT 0,
  `minutes` tinyint(2) DEFAULT 0,
  `hours` int(10) DEFAULT 2,
  `adminlevel` int(10) DEFAULT 0,
  `adminname` varchar(24) DEFAULT 'None',
  `helperlevel` tinyint(2) DEFAULT 0,
  `health` float DEFAULT 100,
  `armor` float DEFAULT 0,
  `upgradepoints` int(10) DEFAULT 0,
  `warnings` tinyint(3) DEFAULT 0,
  `injured` tinyint(1) DEFAULT 0,
  `hospital` tinyint(1) DEFAULT 0,
  `spawnhealth` float DEFAULT 50,
  `spawnarmor` float DEFAULT 0,
  `jailtype` tinyint(1) DEFAULT 0,
  `jailtime` int(10) DEFAULT 0,
  `newbiemuted` tinyint(1) DEFAULT 0,
  `helpmuted` tinyint(1) DEFAULT 0,
  `admuted` tinyint(1) DEFAULT 0,
  `livemuted` tinyint(1) DEFAULT 0,
  `globalmuted` tinyint(1) DEFAULT 0,
  `reportmuted` tinyint(2) DEFAULT 0,
  `reportwarns` tinyint(2) DEFAULT 0,
  `fightstyle` tinyint(2) DEFAULT 4,
  `locked` tinyint(1) DEFAULT 0,
  `accent` varchar(16) DEFAULT 'None',
  `cookies` int(10) DEFAULT 0,
  `phone` int(10) DEFAULT 0,
  `job` int(10) DEFAULT -1,
  `secondjob` tinyint(2) DEFAULT -1,
  `crimes` int(10) DEFAULT 0,
  `arrested` int(10) DEFAULT 0,
  `wantedlevel` tinyint(2) DEFAULT 0,
  `materials` int(10) DEFAULT 2500,
  `weed` int(10) DEFAULT 0,
  `cocaine` int(10) DEFAULT 0,
  `meth` int(10) DEFAULT 0,
  `painkillers` int(10) DEFAULT 0,
  `seeds` int(10) DEFAULT 0,
  `ephedrine` int(10) DEFAULT 0,
  `muriaticacid` int(10) DEFAULT 0,
  `bakingsoda` int(10) DEFAULT 0,
  `cigars` int(10) DEFAULT 0,
  `walkietalkie` tinyint(1) DEFAULT 0,
  `channel` int(10) DEFAULT 0,
  `rentinghouse` int(10) DEFAULT 0,
  `spraycans` int(10) DEFAULT 0,
  `boombox` tinyint(1) DEFAULT 0,
  `mp3player` tinyint(1) DEFAULT 0,
  `phonebook` tinyint(1) DEFAULT 0,
  `fishingrod` tinyint(1) DEFAULT 0,
  `fishingbait` int(10) DEFAULT 0,
  `fishweight` int(10) DEFAULT 0,
  `components` int(10) DEFAULT 0,
  `courierskill` int(10) DEFAULT 0,
  `fishingskill` int(10) DEFAULT 0,
  `guardskill` int(10) DEFAULT 0,
  `weaponskill` int(10) DEFAULT 0,
  `mechanicskill` int(10) DEFAULT 0,
  `lawyerskill` int(10) DEFAULT 0,
  `detectiveskill` int(10) DEFAULT 0,
  `smugglerskill` int(10) DEFAULT 0,
  `toggletextdraws` tinyint(1) DEFAULT 0,
  `togglebug` tinyint(1) DEFAULT 0,
  `toggleooc` tinyint(1) DEFAULT 0,
  `togglephone` tinyint(1) DEFAULT 0,
  `toggleadmin` tinyint(1) DEFAULT 0,
  `togglehelper` tinyint(1) DEFAULT 0,
  `togglenewbie` tinyint(1) DEFAULT 0,
  `togglewt` tinyint(1) DEFAULT 0,
  `toggleradio` tinyint(1) DEFAULT 0,
  `togglevip` tinyint(1) DEFAULT 0,
  `togglemusic` tinyint(1) DEFAULT 0,
  `togglefaction` tinyint(1) DEFAULT 0,
  `togglegang` tinyint(1) DEFAULT 0,
  `togglenews` tinyint(1) DEFAULT 0,
  `toggleglobal` tinyint(1) DEFAULT 1,
  `togglecam` tinyint(1) DEFAULT 0,
  `carlicense` tinyint(1) DEFAULT 0,
  `vippackage` tinyint(2) DEFAULT 1,
  `viptime` int(10) DEFAULT 0,
  `vipcooldown` int(10) DEFAULT 0,
  `weapon_0` tinyint(2) DEFAULT 0,
  `weapon_1` tinyint(2) DEFAULT 0,
  `weapon_2` tinyint(2) DEFAULT 0,
  `weapon_3` tinyint(2) DEFAULT 0,
  `weapon_4` tinyint(2) DEFAULT 0,
  `weapon_5` tinyint(2) DEFAULT 0,
  `weapon_6` tinyint(2) DEFAULT 0,
  `weapon_7` tinyint(2) DEFAULT 0,
  `weapon_8` tinyint(2) DEFAULT 0,
  `weapon_9` tinyint(2) DEFAULT 0,
  `weapon_10` tinyint(2) DEFAULT 0,
  `weapon_11` tinyint(2) DEFAULT 0,
  `weapon_12` tinyint(2) DEFAULT 0,
  `ammo_0` smallint(5) DEFAULT 0,
  `ammo_1` smallint(5) DEFAULT 0,
  `ammo_2` smallint(5) DEFAULT 0,
  `ammo_3` smallint(5) DEFAULT 0,
  `ammo_4` smallint(5) DEFAULT 0,
  `ammo_5` smallint(5) DEFAULT 0,
  `ammo_6` smallint(5) DEFAULT 0,
  `ammo_7` smallint(5) DEFAULT 0,
  `ammo_8` smallint(5) DEFAULT 0,
  `ammo_9` smallint(5) DEFAULT 0,
  `ammo_10` smallint(5) DEFAULT 0,
  `ammo_11` smallint(5) DEFAULT 0,
  `ammo_12` smallint(5) DEFAULT 0,
  `faction` tinyint(2) DEFAULT -1,
  `gang` tinyint(2) DEFAULT -1,
  `factionrank` tinyint(2) DEFAULT 0,
  `gangrank` tinyint(2) DEFAULT 0,
  `division` tinyint(2) DEFAULT -1,
  `contracted` int(10) DEFAULT 0,
  `contractby` varchar(24) DEFAULT 'Nobody',
  `bombs` int(10) DEFAULT 0,
  `completedhits` int(10) DEFAULT 0,
  `failedhits` int(10) DEFAULT 0,
  `reports` int(10) DEFAULT 0,
  `helprequests` int(10) DEFAULT 0,
  `speedometer` tinyint(1) DEFAULT 1,
  `factionmod` tinyint(1) DEFAULT 0,
  `gangmod` tinyint(1) DEFAULT 0,
  `banappealer` tinyint(1) DEFAULT 0,
  `helpermanager` tinyint(1) DEFAULT 0,
  `dynamicadmin` tinyint(1) DEFAULT 0,
  `adminpersonnel` tinyint(1) DEFAULT 0,
  `weedplanted` tinyint(1) DEFAULT 0,
  `weedtime` int(10) DEFAULT 0,
  `weedgrams` int(10) DEFAULT 0,
  `weed_x` float DEFAULT 0,
  `weed_y` float DEFAULT 0,
  `weed_z` float DEFAULT 0,
  `weed_a` float DEFAULT 0,
  `inventoryupgrade` int(10) DEFAULT 0,
  `addictupgrade` int(10) DEFAULT 0,
  `traderupgrade` int(10) DEFAULT 0,
  `assetupgrade` int(10) DEFAULT 0,
  `pistolammo` smallint(5) DEFAULT 0,
  `shotgunammo` smallint(5) DEFAULT 0,
  `smgammo` smallint(5) DEFAULT 0,
  `arammo` smallint(5) DEFAULT 0,
  `rifleammo` smallint(5) DEFAULT 0,
  `hpammo` smallint(5) DEFAULT 0,
  `poisonammo` smallint(5) DEFAULT 0,
  `fmjammo` smallint(5) DEFAULT 0,
  `ammotype` tinyint(2) DEFAULT 0,
  `ammoweapon` tinyint(2) DEFAULT 0,
  `dmwarnings` tinyint(2) DEFAULT 0,
  `weaponrestricted` int(10) DEFAULT 0,
  `referral_uid` int(10) DEFAULT 0,
  `refercount` int(10) DEFAULT 0,
  `watch` tinyint(1) DEFAULT 0,
  `gps` tinyint(1) DEFAULT 0,
  `prisonedby` varchar(24) DEFAULT 'No-one',
  `prisonreason` varchar(128) DEFAULT 'None',
  `togglehud` tinyint(1) DEFAULT 1,
  `clothes` smallint(3) DEFAULT -1,
  `showturfs` tinyint(1) DEFAULT 0,
  `showlands` tinyint(1) DEFAULT 0,
  `watchon` tinyint(1) DEFAULT 0,
  `gpson` tinyint(1) DEFAULT 0,
  `doublexp` int(10) DEFAULT 0,
  `couriercooldown` int(10) DEFAULT 0,
  `pizzacooldown` int(10) DEFAULT 0,
  `detectivecooldown` int(10) DEFAULT 0,
  `gascan` tinyint(1) DEFAULT NULL,
  `duty` int(1) DEFAULT NULL,
  `bandana` tinyint(10) DEFAULT NULL,
  `login_date` date DEFAULT NULL,
  `FormerAdmin` tinyint(3) NOT NULL DEFAULT 0,
  `customtitle` varchar(128) NOT NULL,
  `customcolor` int(10) NOT NULL DEFAULT -256,
  `scanneron` tinyint(1) DEFAULT 0,
  `rimkits` int(10) DEFAULT 0,
  `bodykits` int(10) DEFAULT 0,
  `policescanner` tinyint(1) DEFAULT 0,
  `firstaid` int(10) DEFAULT 0,
  `extraSongs` int(11) NOT NULL DEFAULT 0,
  `top10` tinyint(1) NOT NULL DEFAULT 1,
  `totalfires` int(10) DEFAULT 0,
  `totalpatients` int(10) DEFAULT 0,
  `money_earned` bigint(20) DEFAULT 0,
  `money_spent` bigint(20) DEFAULT 0,
  `rope` int(10) DEFAULT 0,
  `blindfold` int(10) DEFAULT 0,
  `insurance` tinyint(1) DEFAULT 0,
  `adminhide` tinyint(1) DEFAULT 0,
  `passportphone` int(10) DEFAULT 0,
  `passportskin` smallint(3) DEFAULT 0,
  `passportlevel` int(10) DEFAULT 0,
  `passportname` varchar(24) DEFAULT 'None',
  `passport` tinyint(1) DEFAULT 0,
  `globalmutetime` int(10) DEFAULT 0,
  `reportmutetime` int(10) DEFAULT 0,
  `newbiemutetime` int(10) DEFAULT 0,
  `togglereports` tinyint(1) DEFAULT 0,
  `thiefcooldown` int(10) DEFAULT 0,
  `crackcooldown` int(10) DEFAULT 0,
  `laborupgrade` int(10) DEFAULT 0,
  `scripter` tinyint(1) DEFAULT 0,
  `factionleader` tinyint(1) DEFAULT 0,
  `thiefskill` int(10) DEFAULT 0,
  `togglewhisper` tinyint(1) DEFAULT 0,
  `landkeys` tinyint(3) NOT NULL DEFAULT -1,
  `rarecooldown` int(8) DEFAULT 0,
  `diamonds` smallint(5) DEFAULT 0,
  `bugged` tinyint(1) DEFAULT 0,
  `gameaffairs` tinyint(1) DEFAULT 0,
  `crew` tinyint(2) DEFAULT -1,
  `newbies` mediumint(5) DEFAULT 0,
  `rollerskates` tinyint(2) DEFAULT 0,
  `marriedto` int(10) DEFAULT -1,
  `humanresources` tinyint(1) DEFAULT 0,
  `complaintmod` tinyint(1) DEFAULT 0,
  `webdev` tinyint(1) DEFAULT 0,
  `graphic` tinyint(1) DEFAULT 0,
  `vehlock` tinyint(1) DEFAULT 0,
  `togglepoint` tinyint(1) DEFAULT 0,
  `gunlicense` tinyint(1) DEFAULT 0,
  `togglevehicle` tinyint(1) DEFAULT 0,
  `togglepm` tinyint(1) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Đang đổ dữ liệu cho bảng `users`
--

INSERT INTO `users` (`notoriety`, `passwordchanged`, `uid`, `username`, `password`, `regdate`, `lastlogin`, `ip`, `setup`, `gender`, `age`, `skin`, `camera_x`, `camera_y`, `camera_z`, `pos_x`, `pos_y`, `pos_z`, `pos_a`, `interior`, `world`, `cash`, `bank`, `paycheck`, `level`, `exp`, `minutes`, `hours`, `adminlevel`, `adminname`, `helperlevel`, `health`, `armor`, `upgradepoints`, `warnings`, `injured`, `hospital`, `spawnhealth`, `spawnarmor`, `jailtype`, `jailtime`, `newbiemuted`, `helpmuted`, `admuted`, `livemuted`, `globalmuted`, `reportmuted`, `reportwarns`, `fightstyle`, `locked`, `accent`, `cookies`, `phone`, `job`, `secondjob`, `crimes`, `arrested`, `wantedlevel`, `materials`, `weed`, `cocaine`, `meth`, `painkillers`, `seeds`, `ephedrine`, `muriaticacid`, `bakingsoda`, `cigars`, `walkietalkie`, `channel`, `rentinghouse`, `spraycans`, `boombox`, `mp3player`, `phonebook`, `fishingrod`, `fishingbait`, `fishweight`, `components`, `courierskill`, `fishingskill`, `guardskill`, `weaponskill`, `mechanicskill`, `lawyerskill`, `detectiveskill`, `smugglerskill`, `toggletextdraws`, `togglebug`, `toggleooc`, `togglephone`, `toggleadmin`, `togglehelper`, `togglenewbie`, `togglewt`, `toggleradio`, `togglevip`, `togglemusic`, `togglefaction`, `togglegang`, `togglenews`, `toggleglobal`, `togglecam`, `carlicense`, `vippackage`, `viptime`, `vipcooldown`, `weapon_0`, `weapon_1`, `weapon_2`, `weapon_3`, `weapon_4`, `weapon_5`, `weapon_6`, `weapon_7`, `weapon_8`, `weapon_9`, `weapon_10`, `weapon_11`, `weapon_12`, `ammo_0`, `ammo_1`, `ammo_2`, `ammo_3`, `ammo_4`, `ammo_5`, `ammo_6`, `ammo_7`, `ammo_8`, `ammo_9`, `ammo_10`, `ammo_11`, `ammo_12`, `faction`, `gang`, `factionrank`, `gangrank`, `division`, `contracted`, `contractby`, `bombs`, `completedhits`, `failedhits`, `reports`, `helprequests`, `speedometer`, `factionmod`, `gangmod`, `banappealer`, `helpermanager`, `dynamicadmin`, `adminpersonnel`, `weedplanted`, `weedtime`, `weedgrams`, `weed_x`, `weed_y`, `weed_z`, `weed_a`, `inventoryupgrade`, `addictupgrade`, `traderupgrade`, `assetupgrade`, `pistolammo`, `shotgunammo`, `smgammo`, `arammo`, `rifleammo`, `hpammo`, `poisonammo`, `fmjammo`, `ammotype`, `ammoweapon`, `dmwarnings`, `weaponrestricted`, `referral_uid`, `refercount`, `watch`, `gps`, `prisonedby`, `prisonreason`, `togglehud`, `clothes`, `showturfs`, `showlands`, `watchon`, `gpson`, `doublexp`, `couriercooldown`, `pizzacooldown`, `detectivecooldown`, `gascan`, `duty`, `bandana`, `login_date`, `FormerAdmin`, `customtitle`, `customcolor`, `scanneron`, `rimkits`, `bodykits`, `policescanner`, `firstaid`, `extraSongs`, `top10`, `totalfires`, `totalpatients`, `money_earned`, `money_spent`, `rope`, `blindfold`, `insurance`, `adminhide`, `passportphone`, `passportskin`, `passportlevel`, `passportname`, `passport`, `globalmutetime`, `reportmutetime`, `newbiemutetime`, `togglereports`, `thiefcooldown`, `crackcooldown`, `laborupgrade`, `scripter`, `factionleader`, `thiefskill`, `togglewhisper`, `landkeys`, `rarecooldown`, `diamonds`, `bugged`, `gameaffairs`, `crew`, `newbies`, `rollerskates`, `marriedto`, `humanresources`, `complaintmod`, `webdev`, `graphic`, `vehlock`, `togglepoint`, `gunlicense`, `togglevehicle`, `togglepm`) VALUES
(0, 1, 35, 'Kiet_Le', 'D3E95DFEF1354764C469BFCAAC8FCDB3ECDBF6E8C75DE8A50DC92FF86EE6BA4FB39475F109C8CBFC413C6E396355902B253A9E3355B9845BF87B342B9C2D2ACF', NULL, '2021-06-24 17:04:11', '127.0.0.1', 0, 1, 32, 299, 1171.85, -1325.31, 16.038, 1172.51, -1325.31, 15.404, 270, 0, 0, 48500, 150000, 2954, 1, 0, 63, 2, 9, 'None', 0, 100, 0, 0, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 'None', 0, 0, 6, -1, 0, 0, 0, 2500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 9, 0, -1, 0, 'Nobody', 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 'No-one', 'None', 1, -1, 0, 0, 0, 1, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, '', -256, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1500, 0, 0, 0, 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 2712, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `vehicles`
--

CREATE TABLE `vehicles` (
  `id` int(10) NOT NULL,
  `ownerid` int(10) DEFAULT 0,
  `owner` varchar(24) DEFAULT 'Nobody',
  `modelid` smallint(3) DEFAULT 0,
  `price` int(10) DEFAULT 0,
  `tickets` int(10) DEFAULT 0,
  `locked` tinyint(1) DEFAULT 0,
  `plate` varchar(32) DEFAULT 'None',
  `fuel` tinyint(3) DEFAULT 100,
  `health` float DEFAULT 1000,
  `pos_x` float DEFAULT 0,
  `pos_y` float DEFAULT 0,
  `pos_z` float DEFAULT 0,
  `pos_a` float DEFAULT 0,
  `color1` smallint(3) DEFAULT 0,
  `color2` smallint(3) DEFAULT 0,
  `paintjob` tinyint(2) DEFAULT -1,
  `interior` tinyint(2) DEFAULT 0,
  `world` int(10) DEFAULT 0,
  `neon` smallint(5) DEFAULT 0,
  `neonenabled` tinyint(1) DEFAULT 0,
  `trunk` tinyint(1) DEFAULT 0,
  `mod_1` smallint(4) DEFAULT 0,
  `mod_2` smallint(4) DEFAULT 0,
  `mod_3` smallint(4) DEFAULT 0,
  `mod_4` smallint(4) DEFAULT 0,
  `mod_5` smallint(4) DEFAULT 0,
  `mod_6` smallint(4) DEFAULT 0,
  `mod_7` smallint(4) DEFAULT 0,
  `mod_8` smallint(4) DEFAULT 0,
  `mod_9` smallint(4) DEFAULT 0,
  `mod_10` smallint(4) DEFAULT 0,
  `mod_11` smallint(4) DEFAULT 0,
  `mod_12` smallint(4) DEFAULT 0,
  `mod_13` smallint(4) DEFAULT 0,
  `mod_14` smallint(4) DEFAULT 0,
  `cash` int(10) DEFAULT 0,
  `materials` int(10) DEFAULT 0,
  `weed` int(10) DEFAULT 0,
  `cocaine` int(10) DEFAULT 0,
  `meth` int(10) DEFAULT 0,
  `painkillers` int(10) DEFAULT 0,
  `weapon_1` tinyint(2) DEFAULT 0,
  `weapon_2` tinyint(2) DEFAULT 0,
  `weapon_3` tinyint(2) DEFAULT 0,
  `ammo_1` smallint(5) DEFAULT 0,
  `ammo_2` smallint(5) DEFAULT 0,
  `ammo_3` smallint(5) DEFAULT 0,
  `gangid` tinyint(2) DEFAULT -1,
  `factiontype` tinyint(2) DEFAULT 0,
  `job` tinyint(2) DEFAULT -1,
  `respawndelay` int(10) DEFAULT 0,
  `pistolammo` smallint(5) DEFAULT 0,
  `shotgunammo` smallint(5) DEFAULT 0,
  `smgammo` smallint(5) DEFAULT 0,
  `arammo` smallint(5) DEFAULT 0,
  `rifleammo` smallint(5) DEFAULT 0,
  `hpammo` smallint(5) DEFAULT 0,
  `poisonammo` smallint(5) DEFAULT 0,
  `fmjammo` smallint(5) DEFAULT 0,
  `vippackage` tinyint(2) NOT NULL DEFAULT 0,
  `alarm` tinyint(2) NOT NULL DEFAULT 0,
  `weapon_4` tinyint(2) NOT NULL DEFAULT 0,
  `weapon_5` tinyint(2) NOT NULL DEFAULT 0,
  `siren` tinyint(2) DEFAULT 0,
  `rank` tinyint(3) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `weapons`
--

CREATE TABLE `weapons` (
  `uid` int(10) DEFAULT NULL,
  `slot` tinyint(2) DEFAULT NULL,
  `weaponid` tinyint(2) DEFAULT NULL,
  `ammo` smallint(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Chỉ mục cho các bảng đã đổ
--

--
-- Chỉ mục cho bảng `achievements`
--
ALTER TABLE `achievements`
  ADD UNIQUE KEY `uid` (`uid`,`achievement`);

--
-- Chỉ mục cho bảng `atms`
--
ALTER TABLE `atms`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `bans`
--
ALTER TABLE `bans`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `businesses`
--
ALTER TABLE `businesses`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `changes`
--
ALTER TABLE `changes`
  ADD UNIQUE KEY `slot` (`slot`);

--
-- Chỉ mục cho bảng `charges`
--
ALTER TABLE `charges`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `clothing`
--
ALTER TABLE `clothing`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `crews`
--
ALTER TABLE `crews`
  ADD UNIQUE KEY `id` (`id`,`crewid`);

--
-- Chỉ mục cho bảng `divisions`
--
ALTER TABLE `divisions`
  ADD UNIQUE KEY `id` (`id`,`divisionid`);

--
-- Chỉ mục cho bảng `entrances`
--
ALTER TABLE `entrances`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `factionlockers`
--
ALTER TABLE `factionlockers`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `factionpay`
--
ALTER TABLE `factionpay`
  ADD UNIQUE KEY `id` (`id`,`rank`);

--
-- Chỉ mục cho bảng `factionranks`
--
ALTER TABLE `factionranks`
  ADD UNIQUE KEY `id` (`id`,`rank`);

--
-- Chỉ mục cho bảng `factions`
--
ALTER TABLE `factions`
  ADD UNIQUE KEY `id` (`id`);

--
-- Chỉ mục cho bảng `factionskins`
--
ALTER TABLE `factionskins`
  ADD UNIQUE KEY `id` (`id`,`slot`);

--
-- Chỉ mục cho bảng `flags`
--
ALTER TABLE `flags`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `furniture`
--
ALTER TABLE `furniture`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `gangranks`
--
ALTER TABLE `gangranks`
  ADD UNIQUE KEY `id` (`id`,`rank`);

--
-- Chỉ mục cho bảng `gangskins`
--
ALTER TABLE `gangskins`
  ADD UNIQUE KEY `id` (`id`,`slot`);

--
-- Chỉ mục cho bảng `garages`
--
ALTER TABLE `garages`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `id` (`id`);

--
-- Chỉ mục cho bảng `graffiti`
--
ALTER TABLE `graffiti`
  ADD PRIMARY KEY (`graffitiID`);

--
-- Chỉ mục cho bảng `gunracks`
--
ALTER TABLE `gunracks`
  ADD PRIMARY KEY (`rackID`);

--
-- Chỉ mục cho bảng `houses`
--
ALTER TABLE `houses`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `kills`
--
ALTER TABLE `kills`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `landobjects`
--
ALTER TABLE `landobjects`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `lands`
--
ALTER TABLE `lands`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `locations`
--
ALTER TABLE `locations`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_admin`
--
ALTER TABLE `log_admin`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_bans`
--
ALTER TABLE `log_bans`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_cheat`
--
ALTER TABLE `log_cheat`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_contracts`
--
ALTER TABLE `log_contracts`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_cp`
--
ALTER TABLE `log_cp`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_dicebet`
--
ALTER TABLE `log_dicebet`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_faction`
--
ALTER TABLE `log_faction`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_gang`
--
ALTER TABLE `log_gang`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_give`
--
ALTER TABLE `log_give`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_givecookie`
--
ALTER TABLE `log_givecookie`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_givegun`
--
ALTER TABLE `log_givegun`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_givemoney`
--
ALTER TABLE `log_givemoney`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_makeadmin`
--
ALTER TABLE `log_makeadmin`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_makehelper`
--
ALTER TABLE `log_makehelper`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_namechanges`
--
ALTER TABLE `log_namechanges`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_namehistory`
--
ALTER TABLE `log_namehistory`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_property`
--
ALTER TABLE `log_property`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_punishments`
--
ALTER TABLE `log_punishments`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_referrals`
--
ALTER TABLE `log_referrals`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_setstat`
--
ALTER TABLE `log_setstat`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `log_vip`
--
ALTER TABLE `log_vip`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `phonebook`
--
ALTER TABLE `phonebook`
  ADD UNIQUE KEY `number` (`number`);

--
-- Chỉ mục cho bảng `shots`
--
ALTER TABLE `shots`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `speedcameras`
--
ALTER TABLE `speedcameras`
  ADD PRIMARY KEY (`speedID`);

--
-- Chỉ mục cho bảng `spray_tags`
--
ALTER TABLE `spray_tags`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `turfs`
--
ALTER TABLE `turfs`
  ADD UNIQUE KEY `id` (`id`);

--
-- Chỉ mục cho bảng `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`uid`);

--
-- Chỉ mục cho bảng `vehicles`
--
ALTER TABLE `vehicles`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `weapons`
--
ALTER TABLE `weapons`
  ADD UNIQUE KEY `uid` (`uid`,`slot`);

--
-- AUTO_INCREMENT cho các bảng đã đổ
--

--
-- AUTO_INCREMENT cho bảng `atms`
--
ALTER TABLE `atms`
  MODIFY `id` int(4) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT cho bảng `bans`
--
ALTER TABLE `bans`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;

--
-- AUTO_INCREMENT cho bảng `businesses`
--
ALTER TABLE `businesses`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=418;

--
-- AUTO_INCREMENT cho bảng `charges`
--
ALTER TABLE `charges`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=108;

--
-- AUTO_INCREMENT cho bảng `clothing`
--
ALTER TABLE `clothing`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7332;

--
-- AUTO_INCREMENT cho bảng `entrances`
--
ALTER TABLE `entrances`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=320;

--
-- AUTO_INCREMENT cho bảng `factionlockers`
--
ALTER TABLE `factionlockers`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT cho bảng `flags`
--
ALTER TABLE `flags`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=35;

--
-- AUTO_INCREMENT cho bảng `furniture`
--
ALTER TABLE `furniture`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=243;

--
-- AUTO_INCREMENT cho bảng `garages`
--
ALTER TABLE `garages`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT cho bảng `graffiti`
--
ALTER TABLE `graffiti`
  MODIFY `graffitiID` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT cho bảng `gunracks`
--
ALTER TABLE `gunracks`
  MODIFY `rackID` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT cho bảng `houses`
--
ALTER TABLE `houses`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=106;

--
-- AUTO_INCREMENT cho bảng `kills`
--
ALTER TABLE `kills`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2790;

--
-- AUTO_INCREMENT cho bảng `landobjects`
--
ALTER TABLE `landobjects`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16905;

--
-- AUTO_INCREMENT cho bảng `lands`
--
ALTER TABLE `lands`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=170;

--
-- AUTO_INCREMENT cho bảng `locations`
--
ALTER TABLE `locations`
  MODIFY `id` int(4) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=37;

--
-- AUTO_INCREMENT cho bảng `log_admin`
--
ALTER TABLE `log_admin`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6111;

--
-- AUTO_INCREMENT cho bảng `log_bans`
--
ALTER TABLE `log_bans`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=266;

--
-- AUTO_INCREMENT cho bảng `log_cheat`
--
ALTER TABLE `log_cheat`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=289;

--
-- AUTO_INCREMENT cho bảng `log_contracts`
--
ALTER TABLE `log_contracts`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=188;

--
-- AUTO_INCREMENT cho bảng `log_cp`
--
ALTER TABLE `log_cp`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT cho bảng `log_dicebet`
--
ALTER TABLE `log_dicebet`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3657;

--
-- AUTO_INCREMENT cho bảng `log_faction`
--
ALTER TABLE `log_faction`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1488;

--
-- AUTO_INCREMENT cho bảng `log_gang`
--
ALTER TABLE `log_gang`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1338;

--
-- AUTO_INCREMENT cho bảng `log_give`
--
ALTER TABLE `log_give`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2099;

--
-- AUTO_INCREMENT cho bảng `log_givecookie`
--
ALTER TABLE `log_givecookie`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT cho bảng `log_givegun`
--
ALTER TABLE `log_givegun`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT cho bảng `log_givemoney`
--
ALTER TABLE `log_givemoney`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT cho bảng `log_makeadmin`
--
ALTER TABLE `log_makeadmin`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=27;

--
-- AUTO_INCREMENT cho bảng `log_makehelper`
--
ALTER TABLE `log_makehelper`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT cho bảng `log_namechanges`
--
ALTER TABLE `log_namechanges`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=412;

--
-- AUTO_INCREMENT cho bảng `log_namehistory`
--
ALTER TABLE `log_namehistory`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT cho bảng `log_property`
--
ALTER TABLE `log_property`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=807;

--
-- AUTO_INCREMENT cho bảng `log_punishments`
--
ALTER TABLE `log_punishments`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=768;

--
-- AUTO_INCREMENT cho bảng `log_referrals`
--
ALTER TABLE `log_referrals`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT cho bảng `log_setstat`
--
ALTER TABLE `log_setstat`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT cho bảng `log_vip`
--
ALTER TABLE `log_vip`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=526;

--
-- AUTO_INCREMENT cho bảng `shots`
--
ALTER TABLE `shots`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT cho bảng `speedcameras`
--
ALTER TABLE `speedcameras`
  MODIFY `speedID` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=101;

--
-- AUTO_INCREMENT cho bảng `spray_tags`
--
ALTER TABLE `spray_tags`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT cho bảng `users`
--
ALTER TABLE `users`
  MODIFY `uid` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=36;

--
-- AUTO_INCREMENT cho bảng `vehicles`
--
ALTER TABLE `vehicles`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1040;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

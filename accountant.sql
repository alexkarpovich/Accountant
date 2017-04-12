/*
Navicat SQLite Data Transfer

Source Server         : Accountant
Source Server Version : 31300
Source Host           : :0

Target Server Type    : SQLite
Target Server Version : 31300
File Encoding         : 65001

Date: 2017-04-12 21:25:46
*/

PRAGMA foreign_keys = OFF;

-- ----------------------------
-- Table structure for account
-- ----------------------------
DROP TABLE IF EXISTS "account";
CREATE TABLE "account" (
"id"  INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
"currency_id"  INTEGER NOT NULL,
"name"  TEXT(64) NOT NULL,
"amount"  REAL NOT NULL,
"created_at"  INTEGER NOT NULL,
"updated_at"  INTEGER NOT NULL,
FOREIGN KEY ("currency_id") REFERENCES "currency" ("number")
)

;

-- ----------------------------
-- Records of account
-- ----------------------------
BEGIN;
COMMIT;

-- ----------------------------
-- Table structure for accountant
-- ----------------------------
DROP TABLE IF EXISTS "accountant";
CREATE TABLE "accountant" (
"id"  INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
"user_id"  INTEGER,
"account_id"  INTEGER,
"name"  TEXT(128),
"created_at"  INTEGER NOT NULL,
"updated_at"  INTEGER NOT NULL,
FOREIGN KEY ("user_id") REFERENCES "user" ("id"),
FOREIGN KEY ("account_id") REFERENCES "account" ("id")
)

;

-- ----------------------------
-- Records of accountant
-- ----------------------------
BEGIN;
COMMIT;

-- ----------------------------
-- Table structure for country
-- ----------------------------
DROP TABLE IF EXISTS "country";
CREATE TABLE "country" (
"isoN"  INTEGER NOT NULL,
"name"  TEXT(64) NOT NULL,
"iso2"  TEXT(2) NOT NULL,
"iso3"  TEXT(3) NOT NULL,
"created_at"  INTEGER NOT NULL,
"updated_at"  INTEGER NOT NULL,
PRIMARY KEY ("isoN" ASC)
)

;

-- ----------------------------
-- Records of country
-- ----------------------------
BEGIN;
COMMIT;

-- ----------------------------
-- Table structure for currency
-- ----------------------------
DROP TABLE IF EXISTS "currency";
CREATE TABLE "currency" (
"number"  INTEGER NOT NULL,
"country_id"  INTEGER,
"name"  TEXT(64),
"code"  TEXT(3) NOT NULL,
"minor_units"  REAL,
"created_at"  INTEGER NOT NULL,
"updated_at"  INTEGER NOT NULL,
PRIMARY KEY ("number" ASC),
FOREIGN KEY ("country_id") REFERENCES "country" ("isoN")
)

;

-- ----------------------------
-- Records of currency
-- ----------------------------
BEGIN;
COMMIT;

-- ----------------------------
-- Table structure for exchange_rate
-- ----------------------------
DROP TABLE IF EXISTS "exchange_rate";
CREATE TABLE "exchange_rate" (
"id"  INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
"base_number"  INTEGER NOT NULL,
"compare_number"  INTEGER NOT NULL,
"rate"  REAL NOT NULL,
"date"  INTEGER NOT NULL,
"created_at"  INTEGER NOT NULL,
"updated_at"  INTEGER NOT NULL,
FOREIGN KEY ("base_number") REFERENCES "currency" ("number"),
FOREIGN KEY ("compare_number") REFERENCES "currency" ("number")
)

;

-- ----------------------------
-- Records of exchange_rate
-- ----------------------------
BEGIN;
COMMIT;

-- ----------------------------
-- Table structure for expense
-- ----------------------------
DROP TABLE IF EXISTS "expense";
CREATE TABLE "expense" (
"id"  INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
"category_id"  INTEGER NOT NULL,
"account_id"  INTEGER NOT NULL,
"value"  REAL NOT NULL,
"created_at"  INTEGER NOT NULL,
"updated_at"  INTEGER NOT NULL,
FOREIGN KEY ("category_id") REFERENCES "expense_category" ("id")
)

;

-- ----------------------------
-- Records of expense
-- ----------------------------
BEGIN;
COMMIT;

-- ----------------------------
-- Table structure for expense_category
-- ----------------------------
DROP TABLE IF EXISTS "expense_category";
CREATE TABLE "expense_category" (
"id"  INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
"name"  TEXT(128) NOT NULL,
"description"  TEXT,
"created_at"  INTEGER NOT NULL,
"updated_at"  INTEGER NOT NULL
)

;

-- ----------------------------
-- Records of expense_category
-- ----------------------------
BEGIN;
COMMIT;

-- ----------------------------
-- Table structure for sqlite_sequence
-- ----------------------------
DROP TABLE IF EXISTS "sqlite_sequence";
CREATE TABLE "sqlite_sequence" (
"name"  ,
"seq"  
)

;

-- ----------------------------
-- Records of sqlite_sequence
-- ----------------------------
BEGIN;
INSERT INTO "sqlite_sequence" VALUES ('accountant', null);
INSERT INTO "sqlite_sequence" VALUES ('account', 0);
INSERT INTO "sqlite_sequence" VALUES ('expense', 0);
INSERT INTO "sqlite_sequence" VALUES ('exchange_rate', 0);
COMMIT;

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS "user";
CREATE TABLE "user" (
"id"  INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
"username"  TEXT(32) NOT NULL,
"email"  TEXT(64),
"first_name"  TEXT(32),
"last_name"  TEXT(32),
"created_at"  INTEGER NOT NULL,
"updated_at"  INTEGER NOT NULL
)

;

-- ----------------------------
-- Records of user
-- ----------------------------
BEGIN;
COMMIT;

-- ----------------------------
-- Auto increment value for account
-- ----------------------------
UPDATE sqlite_sequence SET seq = 0 WHERE name = "account";

-- ----------------------------
-- Auto increment value for exchange_rate
-- ----------------------------
UPDATE sqlite_sequence SET seq = 0 WHERE name = "exchange_rate";

-- ----------------------------
-- Auto increment value for expense
-- ----------------------------
UPDATE sqlite_sequence SET seq = 0 WHERE name = "expense";
PRAGMA foreign_keys = ON;

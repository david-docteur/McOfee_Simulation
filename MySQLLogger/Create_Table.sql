CREATE TABLE Logger (

	logId int AUTO_INCREMENT NOT NULL PRIMARY KEY,
	logAction varchar(500),
	threatId int NOT NULL
);

SELECT * FROM Logger;

INSERT INTO Logger(lodAction, threatId) VALUES ('deleted', 2);

TRUNCATE TABLE Logger;

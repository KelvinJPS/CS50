CREATE TABLE sells( 
    sellid     INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    userid     TEXT NOT NULL, 
    date       TEXT NOT NULL,
    symbol     TEXT NOT NULL,
    shares     INTEGER NOT NULL, 
    price      INTEGER NOT NULL,
    FOREIGN KEY(userid) REFERENCES users(id)
);
CREATE UNIQUE INDEX sellid ON purchases (sellid);
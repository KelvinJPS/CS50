CREATE TABLE purchases( 
    purchaseid INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    userid     TEXT NOT NULL, 
    date       TEXT NOT NULL,
    symbol     TEXT NOT NULL,
    shares     INTEGER NOT NULL, 
    price      INTEGER NOT NULL,
    FOREIGN KEY(userid) REFERENCES users(id)
);
CREATE UNIQUE INDEX purchaseid ON purchases (purchaseid);

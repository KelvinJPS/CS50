CREATE TABLE transactions( 
    id         INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    userid     INT NOT NULL, 
    date       TEXT NOT NULL,
    symbol     TEXT NOT NULL,
    shares     INTEGER NOT NULL, 
    price      INTEGER NOT NULL,
    FOREIGN KEY(userid) REFERENCES users(id)
);
CREATE UNIQUE INDEX id ON transactions (id);

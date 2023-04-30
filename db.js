const mariadb = require("mariadb");
const isDev = require("./isDev");

var pool;
if (isDev) {
  pool = mariadb.createPool({
    host: "db",
    user: "root",
    password: "password",
    database: "staff_schedule",
  });
} else {
  pool = mariadb.createPool({
    host: "localhost",
    user: "staff_schedule",
    password: "B!t[0D3$",
    database: "staff_schedule",
  });
}

pool.getConnection((err, connection) => {
  if (err) {
    console.error(err);
  }
  if (connection) connection.release();

  return;
});

module.exports = pool;

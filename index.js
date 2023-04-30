const express = require("express");
const path = require("path");
const cors = require("cors");
const isDev = require("./routes/api/isDev");
var cookieParser = require("cookie-parser");
const fs = require("fs");
const app = express();

app.use(cookieParser());

if (isDev) {
  app.use(
    cors({
      origin: ["http://localhost:3000"],
    })
  );
} else {
  app.use(
    cors({
      origin: ["https://kona.ucsd.edu"],
    })
  );
}

app.use(express.static(path.join(__dirname, "public")));

app.use("/static", express.static(path.join(__dirname, "public//static")));
app.use("/api", require("./routes/api/rest"));
app.get("*", function (req, res) {
  res.sendFile("index.html", {
    root: path.join(__dirname, "public/"),
  });
});

app.use(function (req, res, next) {
  res.header("Access-Control-Allow-Credentials", "true");
  next();
});

const PORT = process.env.PORT || 8080;

app.listen(PORT, () => console.log(`Server started on port ${PORT}`));

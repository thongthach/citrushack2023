const express = require("express");
const router = express.Router();
const uuid = require("uuid");
const path = require("path");
const pool = require("./db");
const isDev = require("./isDev");

async function query(query, req) {
  try {
    console.log("going: " + query);

    let rows = await pool.query(query);
    return rows;
  } catch (err) {}
}
// Rest API
router.get("/TrashDepth", async (req, res) => {
  try {
    request = "SELECT * from TrashDepth;";
    data = await query(request, req);
    res.json(data);
  } catch (e) {
    console.error(e);
    res.send(e);
  }
});
router.post("/TrashDepth", async (req, res) => {
  try {
    request =
      "UPDATE TrashDepth SET value = '" +
      req.query.val +
      "' where type = '" +
      req.query.type +
      "';";
    data = await query(request, req);
    res.json(data);
  } catch (e) {
    console.error(e);
    res.send(e);
  }
});
router.get("/TrashCount", async (req, res) => {
  try {
    request = "SELECT * from TrashCount;";
    data = await query(request, req);
    res.json(data);
  } catch (e) {
    console.error(e);
    res.send(e);
  }
});
router.post("/TrashCount", async (req, res) => {
  try {
    request =
      "UPDATE TrashCount SET value = '" +
      req.query.val +
      "' where type = '" +
      req.query.type +
      "';";
    data = await query(request, req);
    res.json(data);
  } catch (e) {
    console.error(e);
    res.send(e);
  }
});
router.get("/Robot", async (req, res) => {
  try {
    request = "SELECT * from Robot;";
    data = await query(request, req);
    res.json(data);
  } catch (e) {
    console.error(e);
    res.send(e);
  }
});
router.post("/Robot", async (req, res) => {
  try {
    request =
      "UPDATE Robot SET value = '" +
      req.query.val +
      "' where type = '" +
      req.query.type +
      "';";
    data = await query(request, req);
    res.json(data);
  } catch (e) {
    console.error(e);
    res.send(e);
  }
});

module.exports = router;

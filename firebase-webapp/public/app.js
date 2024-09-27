// Complete Project Details at: https://RandomNerdTutorials.com/

// Database Paths
var dataHumidityPath = "environment/humidity";
var dataTemperaturePath = "environment/temperature";

// Get a database reference
const databaseHumidity = database.ref(dataHumidityPath);
const databaseTemperature = database.ref(dataTemperaturePath);

// Variables to save database current values
var humidityReading;
var temperatureReading;

// Attach an asynchronous callback to read the data
databaseHumidity.on(
  "value",
  (snapshot) => {
    humidityReading = snapshot.val();
    console.log(humidityReading);
    document.getElementById("reading-humidity").innerHTML = humidityReading;
  },
  (errorObject) => {
    console.log("The read failed: " + errorObject.name);
  }
);

databaseTemperature.on(
  "value",
  (snapshot) => {
    temperatureReading = snapshot.val();
    console.log(temperatureReading);
    document.getElementById("reading-temperature").innerHTML =
      temperatureReading;
  },
  (errorObject) => {
    console.log("The read failed: " + errorObject.name);
  }
);

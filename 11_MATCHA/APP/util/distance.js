// Calculating the distance between two places on the earth
// Using their coordinates (longitude and latitude)

const toRadians = (deg) => {
    return (deg * Math.PI / 180);
}

const evalDistance = (placeA, placeB) => {
    let R = 6371;
    let latA = toRadians(placeA.latitude);
    let latB = toRadians(placeB.latitude);
    let dLat = toRadians(placeB.latitude - placeA.latitude);
    let dLong = toRadians(placeB.longitude - placeA.longitude);

    let a = Math.sin(dLat / 2) * Math.sin(dLat / 2) +
            Math.cos(latA) * Math.cos(latB) *
            Math.sin(dLong / 2) * Math.sin(dLong / 2);
    let c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));

    let d = R * c;
    return (d);
}

module.exports = evalDistance;
// Create an error and throwing it
// The error is registered with given message and status

module.exports = (message, status) => {
    const error = new Error(message);
    error.statusCode = status;
    throw error;
}
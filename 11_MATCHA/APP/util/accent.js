// Various functions that sanitize strings

// Remove french accents from a string
const removeAccent = string => {
    const accent = [
        /[\300-\306]/g, /[\340-\346]/g, // A, a
        /[\310-\313]/g, /[\350-\353]/g, // E, e
        /[\314-\317]/g, /[\354-\357]/g, // I, i
        /[\322-\330]/g, /[\362-\370]/g, // O, o
        /[\331-\334]/g, /[\371-\374]/g, // U, u
        /[\321]/g, /[\361]/g, // N, n
        /[\307]/g, /[\347]/g, // C, c
    ];
    const noaccent = ['A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'N', 'n', 'C', 'c'];

    for (let i = 0; i < accent.length; i++) {
        string = string.replace(accent[i], noaccent[i]);
    }
    return string;
}

// Chek if a given char is alphanumeric
const isLetter = c => {
    const regex = /^[a-zA-Z0-9]$/;
    return regex.test(c);
}

// Clean a string by removing the accents, trimming it, etc.
const cleanString = string => {
    const array = [];
    let newString = removeAccent(string);
    for (let char of newString) {
        if (isLetter(char))
            array.push(char);
    }
    newString = array.join('');
    return newString;
}

module.exports = cleanString;

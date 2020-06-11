// Check if two users are compatible or not
// Returns a boolean
const isCompatible = (userA, userB) => {
    const genreA = userA.usr_gender;
    const genreB = userB.usr_gender;
    const oriA = userA.usr_orientation;
    const oriB = userB.usr_orientation;

    const genreInverse = genreA === 'male' ? 'female' : 'male';
    if (oriA === 'bi') {
        return (oriB === 'bi' || (genreB === genreA && oriB === 'homo') || (genreB === genreInverse && oriB === 'hetero'));
    } else if (oriA === 'homo') {
        return ((genreB === genreA && oriB === 'homo') || (genreB === genreA && oriB === 'bi'));
    } else if (oriA === 'hetero') {
        return ((genreB === genreInverse && oriB === 'hetero') || (genreB === genreInverse && oriB === 'bi'));
    } else {
        return (false);
    }
}


module.exports = isCompatible;
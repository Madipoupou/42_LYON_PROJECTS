const axios = require('axios');

module.exports = (latitude, longitude) => {
    if (!latitude || !longitude)
        return '';
    return axios.get('https://api.opencagedata.com/geocode/v1/json?q=' + latitude + '+' + longitude + '&key=aafdab68af81466d9fcc0b6f307e59f4')
        .then(data => {
            try {
                const precisions = ['city', 'county', 'country'];
                let location = '';
                for (precision of precisions) {
                    if (!!data.data.results[0].components[precision]){
                        location = data.data.results[0].components[precision];
                        break;
                    }
                }
                return location;
            }
            catch (err) {
                return '';
            }
        });
}

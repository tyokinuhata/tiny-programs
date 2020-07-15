const axios = require('axios');
require('dotenv').config();

const token = process.env.PERSONAL_ACCESS_TOKEN;

axios.get('https://api.github.com/user/repos', {
    params: {

    },
    headers: {
        Authorization: `token ${token}`,
    }
}).then(d => {
    console.log(d);
});
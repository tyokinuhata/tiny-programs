const Botkit = require('botkit');

const controller = Botkit.slackbot({
  debug: false,
});

controller.spawn({
  token: 'YOUR_ACCESS_TOKEN'
}).startRTM();

controller.hears('(.*)', ['direct_mention'], (bot, message) => {
  bot.reply(message, 'piyomi');
});

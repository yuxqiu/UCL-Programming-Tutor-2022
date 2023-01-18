// Adapted from Koa Website

const Koa = require('koa');
const app = new Koa();

// response
app.use((ctx, next) => {
    // Do Whatever we want here
    // Maybe log something
    console.log("A new request from " + ctx.request.ip);
    next();
});

app.use(ctx => {
    ctx.body = ctx.request.header;
});

app.listen(3000);
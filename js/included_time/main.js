const isIncludedTime = (time, start, end) => {
    if (start === end) ++end;
    if (start > end) {
        time += 24;
        end += 24;
    }
    if (time >= start && time < end) return true;
    return false;
};

const time = Number(process.argv[2]);
const start = Number(process.argv[3]);
const end = Number(process.argv[4]);

const res = isIncludedTime(time, start, end);
console.log (res);
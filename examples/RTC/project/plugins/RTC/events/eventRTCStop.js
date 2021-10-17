const id = "EVENT_RTC_STOP";
const groups = ["Clock"];
const name = "Stop Clock";

const fields = [
    {
        label: "Stop the Real Time Clock",
    },
];

const compile = (_input, helpers) => {
    const { appendRaw } = helpers;

    appendRaw(`; Stop Clock
VM_RTC_START            .RTC_STOP`);
};

module.exports = {
    id,
    name,
    groups,
    fields,
    compile,
};

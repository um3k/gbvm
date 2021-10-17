const id = "EVENT_RTC_START";
const groups = ["Clock"];
const name = "Start Clock";

const fields = [
    {
        label: "Start the Real Time Clock",
    },
];

const compile = (_input, helpers) => {
    const { appendRaw } = helpers;

    appendRaw(`; Start Clock
VM_RTC_START            .RTC_START`);
};

module.exports = {
    id,
    name,
    groups,
    fields,
    compile,
};

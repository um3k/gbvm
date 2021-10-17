const id = "EVENT_RTC_SET";
const groups = ["Clock"];
const name = "Set Clock Time";

const timeField = (
    label,
    variableFieldKey,
    valueFieldKey,
    typeFieldKey,
    min,
    max
) => {
    return {
        type: "group",
        width: "50%",
        fields: [
            {
                key: variableFieldKey,
                label: label,
                type: "variable",
                defaultValue: "LAST_VARIABLE",
                conditions: [
                    {
                        key: typeFieldKey,
                        eq: "variable",
                    },
                ],
            },
            {
                key: valueFieldKey,
                label: label,
                type: "number",
                defaultValue: 0,
                min: min,
                max: max,
                conditions: [
                    {
                        key: typeFieldKey,
                        eq: "number",
                    },
                ],
            },
            {
                key: typeFieldKey,
                type: "selectbutton",
                options: [
                    ["variable", "variable"],
                    ["number", "number"],
                ],
                inline: true,
                defaultValue: "number",
            },
        ],
    };
};

const fields = [
    timeField("Days", "variableDays", "valueDays", "typeDays", 0, 512),
    timeField("Hours", "variableHours", "valueHours", "typeHours", 0, 23),
    timeField(
        "Minutes",
        "variableMinutes",
        "valueMinutes",
        "typeMinutes",
        0,
        59
    ),
    timeField(
        "Seconds",
        "variableSeconds",
        "valueSeconds",
        "typeSeconds",
        0,
        59
    ),
];

const compile = (input, helpers) => {
    const { appendRaw, getVariableAlias } = helpers;

    const {
        variableDays,
        variableHours,
        variableMinutes,
        variableSeconds,
        valueDays,
        valueHours,
        valueMinutes,
        valueSeconds,
        typeDays,
        typeHours,
        typeMinutes,
        typeSeconds,
    } = input;

    console.log(input, helpers);

    const daysVariableAlias = getVariableAlias(variableDays);
    const hoursVariableAlias = getVariableAlias(variableHours);
    const minutesVariableAlias = getVariableAlias(variableMinutes);
    const secondsVariableAlias = getVariableAlias(variableSeconds);

    appendRaw(`; Clock: Set Clock Time 
${
    typeSeconds === "number"
        ? `VM_PUSH_CONST           ${valueSeconds}`
        : `VM_PUSH_VALUE           ${secondsVariableAlias}`
} ; Seconds
${
    typeMinutes === "number"
        ? `VM_PUSH_CONST           ${valueMinutes}`
        : `VM_PUSH_VALUE           ${minutesVariableAlias}`
} ; Minutes
${
    typeHours === "number"
        ? `VM_PUSH_CONST           ${valueHours}`
        : `VM_PUSH_VALUE           ${hoursVariableAlias}`
} ; Hours
${
    typeDays === "number"
        ? `VM_PUSH_CONST           ${valueDays}`
        : `VM_PUSH_VALUE           ${daysVariableAlias}`
} ; Days

VM_RTC_LATCH
VM_RTC_SET              .ARG3, .RTC_SECONDS 
VM_RTC_SET              .ARG2, .RTC_MINUTES 
VM_RTC_SET              .ARG1, .RTC_HOURS 
VM_RTC_SET              .ARG0, .RTC_DAYS 

VM_POP                  4`);
};

module.exports = {
    id,
    name,
    groups,
    fields,
    compile,
};

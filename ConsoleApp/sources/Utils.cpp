//
// Created by siulo on 06/01/2025.
//

#include "../headers/Utils.h"
#include <iostream>
#include <vector>
#include <headers/domain/shared/StringUtils.h>
#include <wchar.h>

using namespace std;

Utils::Utils() {
}

bool Utils::isNumber(const wstring &value, bool acceptDecimal) {
    bool decimal = false;
    if (value.empty())
        return false;
    for (int i = 0; i < value.length(); i++) {
        if (!isdigit(value[i])) {
            if (i == 0) {
                if (!(value[i] == L'-' || value[i] == L'+'))
                    return false;
            } else {
                if (acceptDecimal && (!decimal)) {
                    if (value[i] == L'.')
                        decimal = true;
                    else
                        return false;
                } else
                    return false;
            }
        }
    }
    return true;
}

wstring Utils::readNumber(const wstring &prompt, bool acceptDecimal) {
    wstring input;
    wstring errorMsg = L"\tNot a number (with no decimals).";
    if (acceptDecimal)
        errorMsg = L"\tNot a number ( use '.' as decimal separator).";
    bool valid = false;
    do {
        input = StringUtils::toUpperCase(StringUtils::trim(readLine(prompt)));
        if (isNumber(input, acceptDecimal)) {
            valid = true;
        } else
            printLine(errorMsg);
    } while (!valid);
    return input;
}

void Utils::printEmptyLine() {
    wcout << endl;
}

void Utils::printEmptyLines(int count) {
    for (int i = 0; i < count; i++)
        printEmptyLine();
}

wstring Utils::string2wstring(const string &str) {
    wstring result(&str[0], &str[str.size()]);
    return result;
}

void Utils::printLine(const string &line) {
    wcout << string2wstring(line) << endl;
}

void Utils::printLines(const vector<string> &lines) {
    for (int i = 0; i < lines.size(); i++)
        printLine(lines[i]);
}

void Utils::printLine(const wstring &line) {
    wcout << line << endl;
}

void Utils::printLines(const vector<wstring> &lines) {
    for (int i = 0; i < lines.size(); i++)
        printLine(lines[i]);
}

wstring Utils::readLine(const wstring &prompt) {
    wstring input;
    wcout << prompt << L": ";
    getline(wcin, input);
    return input;
}

wstring Utils::readNonEmptyLine(const wstring &prompt) {
    wstring input;
    do {
        input = readLine(prompt);
    } while (!StringUtils::ensureNotNullOrEmpty(input));
    return input;
}

bool Utils::readBoolean(const wstring &prompt) {
    wstring input;
    bool valid = false;
    do {
        input = StringUtils::toUpperCase(StringUtils::trim(readLine(prompt + L" (Y/N)")));
        if (input == L"Y" || input == L"N")
            valid = true;
        else
            printLine(L"\tNot a valid input. Please insert Y(es) or N(o) only.");
    } while (!valid);
    return (input == L"Y");
}

int Utils::readInteger(const wstring &prompt) {
    wstring input;
    int result;
    bool valid = false;
    do {
        input = readNumber(prompt, false);
        try {
            result = stoi(input);
            valid = true;
        }
        catch (exception e) {
            printLine(L"\tNot a number (with no decimals).");
        }

    } while (!valid);
    return result;
}

int Utils::readInteger(const wstring &prompt, int min, int max) {
    wstring range = L"(" + to_wstring(min) + L" - " + to_wstring(max) + L")";
    int result;
    bool valid = false;
    do {
        result = readInteger(prompt + range);
        if (!(result < min || result > max))
            valid = true;
        else
            printLine(L"\tNot in the valid range.");
    } while (!valid);
    return result;
}

double Utils::readDouble(const wstring &prompt) {
    wstring input;
    double result;
    bool valid = false;
    do {
        input = readNumber(prompt, true);
        try {
            result = stod(input);
            valid = true;
        }
        catch (exception e) {
            printLine(L"\tNot a number (can have decimals).");
        }

    } while (!valid);
    return result;
}

double Utils::readDouble(const wstring &prompt, double min, double max) {
    wstring range = L" (Range:" + to_wstring(min) + L" - " + to_wstring(max) + L")";
    double result;
    bool valid = false;
    do {
        result = readDouble(prompt + range);
        if (!(result < min || result > max))
            valid = true;
        else
            printLine(L"\tNot in the valid range.");
    } while (!valid);
    return result;
}

optional<int>
Utils::doSelection(const wstring &prompt, const vector<wstring> &options, bool cancel, const wstring &cancelMsg) {
    optional<int> result = nullopt;
    printLine(prompt);
    if (options.size() > 0) {
        for (int i = 0; i < options.size(); i++)
            printLine(L"\t" + to_wstring(i + 1) + L" - " + options[i]);
        printEmptyLine();
        int min = 1;
        if (cancel) {
            printLine(L"\t0 - " + cancelMsg);
            printEmptyLine();
            min--;
        }
        int option = readInteger(L"Your option is ", min, options.size());
        result = make_optional(option - 1);
    } else {
        printLine(L"(No options are available.)");
    }
    return result;
}

void Utils::readEnterToContinue() {
    wstring input;
    printEmptyLine();
    wcout << L"Press <enter> to continue... ";
    getline(wcin, input);
}
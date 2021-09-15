#!/bin/bash

# A valid phone number must appear in
# one of the following two formats
# (xxx) xxx-xxxx or xxx-xxx-xxxx

input="./phoneNumbers.txt"

grep -P "^[0-9]{3}-[0-9]{3}-[0-9]{4}$|^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$" $input

# --- ON MAC need to install GNU grep (brew install grep) ---
# ggrep -P "^[0-9]{3}-[0-9]{3}-[0-9]{4}$|^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$" $input

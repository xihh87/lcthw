#!/bin/sh
set -e

PATH=/home/xihh/progs/lcthw:$PATH
pushd /home/xihh/progs/lcthw/test

echo "Database create"
ex17 prueba1.db create

echo "Set fields..."
ex17 prueba1.db set 0 'Joshua Haase' 'jhaase@elektra.com.mx'
ex17 prueba1.db set 2 'Pablo César Morales Rico' 'pcm@coniima.com.mx'

echo "Too large fields..."
ex17 prueba1.db set 1 'Largo, mi nombre es largo' `for ((i = 0; i < 52; i++)); do echo -n '1234567890'; done`

echo "Show registers..."
ex17 prueba1.db get 0
ex17 prueba1.db get 1
ex17 prueba1.db get 2

echo "List registers..."
ex17 prueba1.db list

echo "Overwrite a registry..."
set +e
if ! ex17 prueba1.db set 1 'pato pato pato' 'pato@pato.com'; then
	echo OK
else
	exit 1
fi
set -e

echo "Delete a registry..."
ex17 prueba1.db del 1


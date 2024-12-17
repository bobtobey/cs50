-- Read crime report for that date and on that street
SELECT description FROM crime_scene_reports WHERE year = 2023 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

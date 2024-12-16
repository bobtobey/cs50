SELECT DISTINCT(name) FROM people ORDER BY birth LIMIT 10;

SELECT year, title FROM movies WHERE year = 2004 LIMIT 10;

SELECT DISTINCT(name) FROM people WHERE id IN (SELECT year FROM movies WHERE year = 2004);

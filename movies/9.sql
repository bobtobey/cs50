SELECT DISTINCT(name) FROM people ORDER BY birth LIMIT 10;

SELECT year, title FROM movies WHERE year = 2004 LIMIT 10;

SELECT DISTINCT(name) FROM people WHERE id IN (SELECT year FROM movies WHERE year = 2004);

SELECT name FROM people WHERE id IN
(SELECT person_id FROM stars
WHERE movie_id IN (SELECT id FROM movies WHERE year = 2004));

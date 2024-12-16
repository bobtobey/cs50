SELECT DISTINCT(name) FROM people ORDER BY birth LIMIT 10;

SELECT year, title FROM movies WHERE year = 2004 LIMIT 10;

SELECT DISTINCT(name) FROM people WHERE id IN (SELECT year FROM movies WHERE year = 2004);

-- find id for movies in 2004 first, then find the person id for stars in those movies, last find the name id of those
SELECT name, COUNT(*) AS c FROM people WHERE id IN
(SELECT person_id FROM stars
WHERE movie_id IN (SELECT id FROM movies WHERE year = 2004));

SELECT DISTINCT(name), birth, year FROM people JOIN stars ON people.id = stars.person_id
JOIN movies on stars.movie_Id = movies.id WHERE year = 2004 ORDER BY birth LIMIT 30;

SELECT name, year, ROW_NUMBER() OVER (ORDER BY birth) AS row_num
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE year = 2004
ORDER BY birth;

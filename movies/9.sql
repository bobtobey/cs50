-- find id for movies in 2004 first, then find the person id for stars in those movies, last find the name id of those
SELECT DISTINCT(name) FROM people JOIN stars ON people.id = stars.person_id
JOIN movies on stars.movie_Id = movies.id WHERE year = 2004 ORDER BY birth LIMIT 30;

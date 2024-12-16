-- join movies table with ratings table to find and sort movies with actor X where movies in stars and stars in people
SELECT title FROM movies AS m JOIN ratings AS r ON m.id = r.movie_id
WHERE m.id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = 'Chadwick Boseman' AND id = 1569276))
ORDER BY rating DESC LIMIT 5;

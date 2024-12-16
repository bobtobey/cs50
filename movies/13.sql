SELECT name, birth, id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958;

SELECT title FROM movies AS m WHERE m.id IN (SELECT movie_id FROM stars AS s WHERE)

SELECT title FROM movies AS m
WHERE m.id IN (Select movie_id FROM stars AS s JOIN people AS p1 ON s.person_id = p1.id WHERE name = 'Bradley Cooper')
AND m.id IN (Select movie_id FROM stars AS s JOIN people AS p1 ON s.person_id = p1.id WHERE name = 'Jennifer Lawrence');

SELECT title FROM movies AS m
JOIN stars AS s ON m.id = s.movie_id
JOIN people AS p ON s.person_id = p.id WHERE name = 'Bradley Cooper' AND name = 'Jennifer Lawrence';

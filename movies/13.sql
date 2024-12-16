SELECT name, birth, id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958;

SELECT title FROM movies AS m WHERE m.id IN
(SELECT movie_id FROM stars AS s JOIN people ON s.person_id = people.id WHERE name = 'Kevin Bacon' AND birth = 1958));

SELECT title FROM movies AS m WHERE m.id IN
(Select movie_id FROM stars AS s JOIN people AS p1 ON s.person_id = p1.id WHERE name = 'Bradley Cooper')

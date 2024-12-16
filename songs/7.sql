SELECT AVG(energy) FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = 'Drake' AND id = 23);

SELECT name, id FROM artists WHERE name = 'Drake';

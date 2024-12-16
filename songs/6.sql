SELECT name, artist_id FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = 'Post Malone');

SELECT name, id FROM artists WHERE name = 'Post Malone';

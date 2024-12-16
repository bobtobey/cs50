SELECT name, artist_id FROM songs WHERE artist_id IN (SELECT id, name FROM songs LIMIT 10;

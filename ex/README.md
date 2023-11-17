# spring-mvc-exercise-2

A partire da quest'esempio:
  -  Implementa una view che mostra i contatti salvati nel DB
  -  Imprementa una view che permette di aggiornare un contatto esistente
  -  Implementa un meccanismo (opzione in una view + metodo del controller) per eliminare un contatto
  -  Implementa un meccanismo di ricerca (ad esempio per nome)

Per cominciare, inizializza il DB.

Crea il database e la tabella corrispondente:

`CREATE DATABASE addressbook;`

`USE addressbook;`

```
create table contact( 
  id int primary key auto_increment, 
  name varchar(40) not null,
  surname varchar(40) not null, 
  email varchar(40) not null
);
```

Crea un nuovo utente per il DB da usare con l'app Spring:

`create user 'springapp'@'localhost' identified by 'password';`

Assegna i corretti privilegi d'accesso, ad esempio:

`grant all privileges on addressbook.contact to 'springapp'@'localhost';`

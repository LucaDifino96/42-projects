package com.exercise.datajdbc.repository;

import com.exercise.datajdbc.entity.Contact;
import org.springframework.data.jdbc.repository.query.Modifying;
import org.springframework.data.jdbc.repository.query.Query;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ContactRepository extends CrudRepository<Contact, Long> {

    @Modifying
    @Query("UPDATE contact SET name = :name, surname = :surname WHERE id = :id")
    boolean updateNameAndSurnameById(Long id, String name, String surname);

}

package com.exercise.datajdbc.service;

import com.exercise.datajdbc.entity.Contact;
import com.exercise.datajdbc.repository.ContactRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class ContactService {

    @Autowired
    private ContactRepository repository;

    public void updateContactName(Long id, String newName, String newSurname) {
        repository.updateNameAndSurnameById(id, newName, newSurname);
    }

    public void addContact(Contact contact) {
        repository.save(contact);
    }

    public List<Contact> getAllContacts() {
        List<Contact> allContacts = new ArrayList<>();
        for (Contact contact : repository.findAll()) {
            allContacts.add(contact);
        }
        return allContacts;
    }

}

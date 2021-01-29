#pragma once
#include <map>
#include <string>

template<typename ResourceType, typename KeyType>
class ResourceHolder
{
    using MapType = std::map<KeyType, ResourceType*>;//Тип контейнера, в котором будем хранить текстуры
public:
    template<typename ... Args>
    ResourceType* loadFromFile(const std::string& fileName, const KeyType& key, Args &&... args)//Загрузка ресурса из файла
    {
        ResourceType*& resourceRef = mResources[key];//Ищем ресурс с заданным ключом. 
        //Если его нет, то он будет вставлен, поэтому ссылка на указатель будет валидной.

        if (resourceRef != nullptr) {//Если элемент с таким ключом уже загружен, 
            return resourceRef;//то просто возвращаем указатель на него
        }
        //Если дошли до сих пор, значит ресурс необходимо загрузить
        resourceRef = new ResourceType();//Создаем новый ресурс и сохраняем указатель на него
        //Загружаем ресурс из файла:
        if (!resourceRef->loadFromFile(fileName, std::forward<Args>(args)...)) {//Если загрузка не удалась,
            delete resourceRef;//Освобождаем ресурс
            resourceRef = nullptr;//Обнуляем указатель (в коде выше сие отсутствует. Бага!)
        }
        return resourceRef;//Возвращаем указатель на ресурс (либо nullptr, если не удалась загрузка)
    }
    //Функция получения указателя на ресурс:
    ResourceType* getResource(const KeyType& key)
    {
        typename MapType::iterator resourcePairIt = mResources.find(key);//Ищем ресурс с заданным ключом
        if (resourcePairIt == mResources.end()) {//Если ресурс не найден, то
            return nullptr;//возвращаем nullptr
        }
        return resourcePairIt->second;//Иначе возвращаем указатель на ресурс (либо nullptr, если ресурс не загружен)
    }




    ~ResourceHolder()
    {
        for (auto& e : mResources) {//Освобождаем память
            delete e.second;
        }
    }

    //Удаляем не нужные конструкторы и операторы присваивания
    ResourceHolder() = default;
    ResourceHolder(const ResourceHolder&) = delete;
    ResourceHolder(ResourceHolder&&) = delete;
    ResourceHolder& operator=(const ResourceHolder&) = delete;
    ResourceHolder& operator=(ResourceHolder&&) = delete;
private:
    MapType mResources;
};




template<typename ResourceType, typename KeyType>
ResourceHolder<ResourceType, KeyType>& getGlobalResourceHolder()
{
    static ResourceHolder<ResourceType, KeyType> holder;//Для каждого хранителя ресурсов будет своя статическая переменная
    return holder;
}
